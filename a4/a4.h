#ifndef A4_H
#define A4_H

#define NUM_CARDS_IN_HAND 5
#define NUM_CARDS_IN_DECK 24

enum suit{HEARTS, CLUBS, SPADES, DIAMONDS};

typedef enum suit Suit; 

enum name{NINE=9, TEN, JACK, QUEEN, KING, ACE};

typedef enum name Name; 

struct card{
	Name name; 
	Suit suit; 
	int value; 
};

typedef struct card Card; 

struct deck{
	Card* cards[NUM_CARDS_IN_DECK]; 
	int topCard; 
};

typedef struct deck Deck; 


struct game_score{
	int player1_score; 
	int player2_score; 
};

typedef struct score GameScore; 


typedef struct card_node CardNode; 

struct card_node{
	CardNode *nextCard; 
	CardNode *prevCard; 
	Card *thisCard; 
};


struct hand{
	int num_cards_in_hand; 
	CardNode *firstCard; 
};

typedef struct hand Hand; 

/*
 * NOTES: 
Here is a summary of how the three structures are 
intended to work in regards to memory:
For each round of the game, you create 2 new Hands, 
deal Cards from the Deck to the Hands. As Players play 
Cards, the cards go back to the Deck (removed from the 
Hand; the CardNode is freed). At the end of the round, 
the Hands go away (are freed), but the Cards are now 
in the Deck and can be re-used for the next round.
The function returnHandToDeck() is a helper that 
takes all the Cards out of the Hand and returns them to 
the Deck.
At the end of the game, destroy the Deck by removing all 
the Cards from the Deck, free them, and free the Deck.
*/

//----------------------------------------
// Deck functions
//----------------------------------------
// Implement these functions in deck.c. 
// Creates the deck to be used for NEUchre. 
// Assume that the value of cards are: 
// Nine=9; Ten=10; Jack=11; and so on, up to Ace=14. 

// Creates the deck, initializing any fields necessary. 
// Returns a pointer to the deck, which has been allocated on the heap. 
Deck* createDeck(); 

// Adds a card to the top of the deck. 
// Returns a pointer to the deck. 
Deck* pushCardToDeck(Card*, Deck*); 

// Shows the top card, but does not remove it from the stack. 
// Returns a pointer to the top card. 
Card* peekAtTopCard(Deck*);

// Removes the top card from the deck and returns it. 
// Returns a pointer to the top card in the deck. 
Card* popCardFromDeck(Deck*);

// Determines if the deck is empty. 
// Returns 0 if the Deck has any cards; 1 otherwise. 
int isDeckEmpty(Deck*);

// Destroys the deck, freeing any memory allocated 
// for this deck (the cards and the deck). 
void destroyDeck(Deck*); 

//----------------------------------------
// Card functions
//----------------------------------------

// Creates a card, initializing the suit and name to that specified.
// Returns a pointer to the new card, which has beel allocated on the heap.
// It is the responsibility of the caller to call destroyCard()
// when it is done with the Card. 
Card* createCard(Suit, Name);

// Destroys the card, freeing any memory allocated for the card. 
void destroyCard(Card*); 

//----------------------------------------
// Hand functions
//----------------------------------------

// Creates a Hand struct and initializes any necessary fields. 
// Returns a pointer to the new Hand, which has been allocated on the heap. 
Hand* createHand();

CardNode* createCardNode(Card*);

// Adds a card to the hand. 
void addCardToHand(Card *card, Hand *hand); 

// Removes a card from the hand. 
Card* removeCardFromHand(Card *card, Hand *hand); 

// Determines if there are any cards in the hand. 
// Return 0 if the hand is empty; 1 otherwise. 
int isHandEmpty(Hand*);

// Destroys the hand, freeing any memory allocated for it. 
void destroyHand(Hand*); 



//----------------------------------------
// Game functions
//----------------------------------------


// Shuffle the deck. 
// Put them in a random order. 
void shuffle(Deck *aDeck); 

// Given a deck (assume that it is already shuffled), 
// take the top card from the deck and alternately give 
// it to player 1 and player 2, until they both have 
// NUM_DECKS_IN_HAND. 
void deal(Deck *aDeck, Hand *p1hand, Hand *p2hand); 

// Create a Deck for this game, and add any 
// needed cards to the deck. 
// Return a pointer to the deck to be used for the game 
Deck* populateDeck(); 


// Given a lead card, a players hand, and the card the player wants 
// to play, is it legal? 
// If the player has a card of the same suit as the ledCard, they 
// must play a card of the same suit. 
// If the player does not have a card of the same suit, they can 
// play any card. 
int isLegalMove(Hand *hand, Card *leadCard, Card *playedCard); 


// Given two cards that are played in a hand, which one wins? 
// If the suits are the same, the higher card value wins. 
// If the suits are not the same, player 1 wins, unless player 2 played trump. 
// Returns 1 if the person who led won, 0 if the person who followed won. 
int whoWon(Card *leadCard, Card *followedCard, Suit trump); 

// Take all the cards out of a given hand, and put them 
// back into the deck. 
void returnHandToDeck(Hand *hand, Deck *deck);

//----------------------------------------
// Challenge functions
//----------------------------------------

// Considering this for a challenge problem. 
Card* getBestMove(Hand *myHand, Card *ledCard, Suit trump); 

// Sort the given hand in descending order of power. 
// 
// The sort order should be: all cards of the given trump should 
// be the "highest", and A high down to 9; 
// The other suits can be in random order, but the card values must go 
// from high to low. 
void sortHand(Hand *hand, Suit trump); 

void shuffleHand(Hand*); 

//----------------------------------------
// Helper functions
//----------------------------------------

void printCard(Card *aCard); 

void printHand(Hand *aHand); 

void printDeck(Deck *aDeck); 

char *getName(Name aCardName); 

char *getSuit(Suit aCardSuit);

#endif 
