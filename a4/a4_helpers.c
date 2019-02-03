#include <stdio.h>

#include "a4.h"

void printCard(Card *aCard){
	printf("%s_%s", getName(aCard->name), getSuit(aCard->suit)); 
}

void printHand(Hand *aHand){
	int i = 0; 

	CardNode *cih = aHand->firstCard; 

	while(cih != NULL){
		printf("%d: ", i++); 
		printCard(cih->thisCard); 
		printf("\n");

		cih = cih->nextCard; 
	}
}


// THIS BREAKS THE ABSTRACTION!
// This method is here as a helper to help you debug. 
// DO NOT follow this pattern to access cards in the deck elsewhere. 
void printDeck(Deck *aDeck){
	int i; 

	for (i=0; i<NUM_CARDS_IN_DECK; i++){
		printf("%d: ", i);
		printCard(aDeck->cards[i]); 
		printf("\n");
	}
}

char *getSuit(Suit suit){
	switch(suit){
		case HEARTS: 
			return "Hearts"; 
		case SPADES: 
			return "Spades"; 
		case CLUBS: 
			return "Clubs";
		case DIAMONDS: 
			return "Diamonds";

		default: 
		return "Unknown Suit";
	}
}

char * getName(Name name){

	switch(name){
		case NINE: 
			return "Nine"; 
		break; 
		case TEN: 
			return "Ten";
		break; 

		case JACK: 
			return "Jack";
		break; 

		case QUEEN: 
			return "Queen";
		break; 

		case KING: 
			return "King";
		break; 

		case ACE: 
			return "Ace";
		break; 

		default: 

		return "Unknown"; 
	}
}

