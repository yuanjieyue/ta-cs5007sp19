#include <stdio.h>
#include <stdlib.h>

#include "a4.h"

#define PRINT_DEBUG 1

// Put your deck functions in here
Deck* createDeck() {
	Deck* deck = (Deck*) malloc(sizeof(Deck));
	deck -> topCard = -1;
	
	int i;
	for (i = 0; i < NUM_CARDS_IN_DECK; i++) {
		deck -> cards[i] = NULL;
	}
	
	return deck;
}

Deck* pushCardToDeck(Card* card, Deck* deck) {
	if (deck -> topCard < NUM_CARDS_IN_DECK - 1) {
		deck -> topCard = deck -> topCard + 1;
		deck -> cards[deck -> topCard] = card;
	}
	return deck;
}

Card* peekAtTopCard(Deck* deck) {
	if (!isDeckEmpty(deck)) {
		return deck -> cards[deck -> topCard];
	}
	return NULL;
}

Card* popCardFromDeck(Deck* deck) {
	if (!isDeckEmpty(deck)) {
		return deck -> cards[deck -> topCard--];
	}
	return NULL;
}

int isDeckEmpty(Deck* deck) {
	if (deck -> topCard > -1) {
		return 0;		
	} else {
		return 1;	
	}
}

void destroyDeck(Deck* deck) {
	deck -> topCard = -1;
	free(deck);
}


