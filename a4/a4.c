#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>

#include "a4.h"

#define PRINT_DEBUG 1

// Implement the Hand and other functions in here
Card* createCard(Suit suit, Name name) {
	Card* card = (Card*) malloc(sizeof(Card));
	card -> name = name;
       	card -> suit = suit;
	card -> value = -1;
	return card;	
}

void destroyCard(Card* card) {
	free(card);
}

Hand* createHand() {
	Hand* hand = (Hand*) malloc(sizeof(Hand));
	hand -> num_cards_in_hand = 0;
	hand -> firstCard = NULL;
	return hand;
}

CardNode* createCardNode(Card* card) {
	CardNode* new_card_node = (CardNode*) malloc(sizeof(CardNode));
	new_card_node -> prevCard = NULL;
	new_card_node -> nextCard = NULL;
	new_card_node -> thisCard = card;
	return new_card_node;
}

void addCardToHand(Card* card, Hand* hand) {
	if (hand -> num_cards_in_hand >= 5) return;

	CardNode* new_card_node = createCardNode(card);
	new_card_node -> thisCard = card;
	if (hand -> num_cards_in_hand > 0) {
		new_card_node -> nextCard = hand -> firstCard;
		hand -> firstCard -> prevCard = new_card_node;
	}
	hand -> num_cards_in_hand++;
	hand -> firstCard = new_card_node;	
}	 

Card* removeCardFromHand(Card *card, Hand *hand) {
	CardNode* curr_card_node;
       	curr_card_node = hand -> firstCard;
	if (hand -> num_cards_in_hand == 0) return card;

	while (curr_card_node != NULL) {
		if (curr_card_node -> thisCard == card) {
			break;
		}
		curr_card_node = curr_card_node -> nextCard;
	}	
	if (curr_card_node == NULL) return card;
	if (curr_card_node == hand -> firstCard) {
		if (curr_card_node -> nextCard == NULL) {
			hand -> firstCard = NULL;	
		} else {
			hand -> firstCard = curr_card_node -> nextCard;
			hand -> firstCard -> prevCard = NULL;
		}
	} else {
		curr_card_node -> prevCard -> nextCard = curr_card_node -> nextCard;
		if (curr_card_node -> nextCard != NULL) {
			curr_card_node -> nextCard -> prevCard = curr_card_node -> prevCard;
		}
	}
	curr_card_node -> nextCard = NULL;
	curr_card_node -> prevCard = NULL;
	curr_card_node -> thisCard = NULL;
	hand -> num_cards_in_hand--;
	free(curr_card_node);
	return card;
}

int isHandEmpty(Hand *hand) {
	if (hand -> num_cards_in_hand == 0) {
		return 0;
	} else {
		return 1;
	}
}

void destroyHand(Hand *hand) {
	while (hand -> firstCard != NULL) {
		CardNode* tmp = hand -> firstCard;
		hand -> firstCard = hand -> firstCard -> nextCard;
		free(tmp);
	}
	
	free(hand);
}


void shuffle(Deck *deck) {
	Card* tmp;
	srand (time(NULL));
	int i, j;
	for (i = NUM_CARDS_IN_DECK - 1; i > 0; i--) {
		j = rand() % (i + 1);
		tmp = deck -> cards[i];
		deck -> cards[i] = deck -> cards[j];
		deck -> cards[j] = tmp;
	}
}

void deal(Deck *aDeck, Hand *p1hand, Hand *p2hand) {
	while (p1hand -> num_cards_in_hand < NUM_CARDS_IN_HAND || p2hand -> num_cards_in_hand < NUM_CARDS_IN_HAND) {
		Card* top;
		if (p1hand -> num_cards_in_hand < NUM_CARDS_IN_HAND && !isDeckEmpty(aDeck)) {
			top = popCardFromDeck(aDeck);
			addCardToHand(top, p1hand);
		}

		if (p2hand -> num_cards_in_hand < NUM_CARDS_IN_HAND && !isDeckEmpty(aDeck)) {
			top = popCardFromDeck(aDeck);
			addCardToHand(top, p2hand);
		}
	}
}	

Deck* populateDeck() {
	Deck* aDeck = createDeck();
	Suit suit = HEARTS;
	Name name = NINE;
	for (; suit <= DIAMONDS; suit++) {
		for (name = NINE; name <= ACE; name++) {
			Card* new_card = (Card*) malloc(sizeof(Card));
			new_card -> name = name;
			new_card -> suit = suit;
			new_card -> value = -1;
			aDeck = pushCardToDeck(new_card, aDeck); 
		}
	}
	return aDeck;
}

int isLegalMove(Hand *hand, Card *leadCard, Card *playedCard) {
	Suit src_suit = leadCard -> suit;
	Suit curr_suit = playedCard -> suit;
	if (src_suit == curr_suit) return 1;

	while (hand -> firstCard != NULL) {
		if (hand -> firstCard -> thisCard -> suit == src_suit) {
			return 0;
		}
		hand -> firstCard = hand -> firstCard -> nextCard;
	}
	return 1;
}

int whoWon(Card *leadCard, Card *followedCard, Suit trump) {
	Suit src_suit = leadCard -> suit;
	Suit curr_suit = followedCard -> suit;
	Name src_name = leadCard -> name;
	Name curr_name = followedCard -> name;
	if (src_suit == curr_suit) {
		return src_name >= curr_name ? 1 : 0;
	} else {
		if (curr_suit == trump) {
			return 0;
		} else {
			return 1;
		}
	}
}

void returnHandToDeck(Hand *hand, Deck *deck) {
	while (hand -> firstCard != NULL) {
		CardNode* first_card = hand -> firstCard;
		Card* curr_card = first_card -> thisCard;
		Card* card_remove = removeCardFromHand(curr_card, hand);
		pushCardToDeck(card_remove, deck);
	}	
}

