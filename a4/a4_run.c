#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

#include "a4.h"

#define PRINT_OUT_DECK 0

#define PRINT_P1_HAND 0


Card* take_player1_turn(Hand *p1hand){
	printf("Player 1 played the card: ");

	printCard(p1hand->firstCard->thisCard);

	Card* out = p1hand->firstCard->thisCard; 

	removeCardFromHand(p1hand->firstCard->thisCard, p1hand);

	printf("\n\n"); 

	return out; 
}

void flush_in(){
	char c; 
	while((c = getchar()) != '\n' && c != EOF){

	}
}

Card* take_player2_turn(Hand *p2hand){
	printf("Player 2's turn: Which card do you want to play?\n"); 
	printHand(p2hand); 
	printf("\n");

	int whichOne = 0; 
	scanf("%d", &whichOne);
	
	while (whichOne > (p2hand->num_cards_in_hand-1)){
		printf("Please choose a number between %d and %d. ", 0, (p2hand->num_cards_in_hand-1)); 
		scanf("%d", &whichOne);
	}

	flush_in(); 

	int i = 0; 

	CardNode *cih = p2hand->firstCard; 

	while (i < whichOne){
		cih = cih->nextCard; 
		i++; 
	}
	printf("Player 2 played the card: ");
	printCard(cih->thisCard) ;
	printf("\n"); 

	Card* out = cih->thisCard; 
	removeCardFromHand(cih->thisCard, p2hand);

	return out; 
}

Suit get_trump(Card *topcard){
	printf("Time to choose trump!\n");
	return rand()%4; 
}

void print_trump(Suit trump){
	printf("\n\n*************************\n");
	printf("**** Trump is %s *****\n", getSuit(trump));
	printf("*************************\n\n");
}


void print_score(int score1, int score2){
	printf("Player 1: %d\tPlayer 2: %d", score1, score2); 
}

// Returns 1 or 2, based on who won. 
int play_round(Deck *gameDeck){


	shuffle(gameDeck); 

	if (PRINT_OUT_DECK){
		printDeck(gameDeck);
	}

	// Deal the hand
	Hand *p1hand = createHand(); 
	Hand *p2hand = createHand(); 

	deal(gameDeck, p1hand, p2hand); 

	printf("\n\n");

	if (PRINT_P1_HAND){
		printf("Player 1: \n");
		printHand(p1hand); 
	}

	// For each round: 

	// Determine trump
	Suit trump = get_trump(peekAtTopCard(gameDeck)); 
	print_trump(trump);

	// Start playing. 
	int num_tricks = 0; 
	int p1score = 0, p2score = 0; 
	Card *ledCard, *followedCard; 

	printf("\n\n"); 
	printf("Starting the round...");

	while (num_tricks < NUM_CARDS_IN_HAND){
		printf("\n---------------------\n"); 

		ledCard = take_player1_turn(p1hand); 
		followedCard = take_player2_turn(p2hand); 

		if (isLegalMove(p2hand, ledCard, followedCard)){
			// figure out who won

			if(whoWon(ledCard, followedCard, trump)){
				printf("Player 1 took the trick. \n"); 
				// P1 won			
				p1score++; 
			}
			else{
				printf("Player 2 took the trick. \n"); 
				// P2 won
				p2score++; 
			}
			printf("\n"); 
			print_score(p1score, p2score); 
			printf("\n"); 
		}
		else{
			// It was not a legal move; player 2 loses!
			printf("\n\nPlayer 2 did not make a legal move!! \n"); 
			printf("The round is over. \n"); 
			printf("Player 1 wins by default. \n"); 
			p2score = -1; 

			// Put the cards back in the deck 
			// so we don't "lose" them
			pushCardToDeck(ledCard, gameDeck); 
			pushCardToDeck(followedCard, gameDeck);
			break; 
		}

		// Put the cards back in the deck.
		pushCardToDeck(ledCard, gameDeck); 
		pushCardToDeck(followedCard, gameDeck);


		num_tricks++; 
	}

	if (p2score > 0){
		printf("\n\n"); 
		printf("Player %d won this round with %d tricks!\n", 
			(p1score > p2score ? 1 : 2), 
			(p1score > p2score ? p1score : p2score));
	}

	returnHandToDeck(p1hand, gameDeck); 
	returnHandToDeck(p2hand, gameDeck); 

	destroyHand(p1hand);
	destroyHand(p2hand); 

	return (p1score > p2score ? 1 : 2); 
}

int play_game(Deck *gameDeck){
	int num_rounds = 5; 

	int which_player_won, i; 

	int player1score = 0, player2score = 0; 

	for (i=0; i<num_rounds; i++){

		printf("\n\n===========================\n");
		printf("Round # %d\n", i+1);
		printf("===========================\n\n");

		which_player_won = play_round(gameDeck); 
		
		if (which_player_won == 1){
			player1score++; 
		}
		else{
			player2score++; 
		}

		printf("\n\n\n");
		printf("Game Score so far: \n"); 
		print_score(player1score, player2score); 
		printf("\n===========================\n\n");

		char input[5]; 
		 
		printf("When you're ready, press <enter> to go to the next round. \n"); 
		char whichOne = getchar(); 

	}



	printf("\n\n"); 
	printf("Player %d won the game!\n", 
		(player1score > player2score ? 1 : 2)); 

	print_score(player1score, player2score); 

	printf("\n\n"); 
	return (player1score > player2score ? 1 : 2); 
}

int main(){
	srand(time(NULL));

	printf("Welcome to NEUchre!\n");
	printf("When you're ready to play, press <enter>\n"); 


	char in; 
	in = getchar(); 

	printf("Okay. "); 

	Deck *gameDeck = populateDeck(); 

	if (PRINT_OUT_DECK){
		printDeck(gameDeck);
	}

	printf("Would you like to play a [R]ound or a [G]ame?\n"); 

	in = getchar(); 
	

		switch(in){
		case 'r': 
		play_round(gameDeck);
		break; 
		case 'g': 
			play_game(gameDeck)	;
		break; 
		default: 
			printf("Quitting the game. "); 

	}


	// Don't forget to free the deck! 
	// I created it in this function, going to free it in this function. 

	destroyDeck(gameDeck); 

}
