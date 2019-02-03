#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a4.h"

#define assert(EXPRESSION) ((EXPRESSION) ? _assert_pass(#EXPRESSION, __FILE__, __LINE__) : \
                                           _assert_fail(#EXPRESSION, __FILE__, __LINE__))

void _assert_fail(const char* expression, const char* file, int line)
{
  fprintf(stderr, "\n**** Assertion '%s' FAILED, file '%s' line '%d' *******.\n", expression, file, line);
}

void _assert_pass(const char *expression, const char *file, int line)
{
  fprintf(stdout, "Assertion '%s' passed, file '%s' line '%d'.\n", expression, file, line);
}

void start_test(const char *test)
{
  static int count = 1;
  printf("Test #%d: %s\n\n", count++, test);
}

void end_test()
{
  printf("\n--------------------------------\n\n");
}

void test_create_deck()
{
  start_test("create_deck");

  Deck *deck = createDeck();

  // deck should be empty at this stage
  assert(deck->topCard < 1);

  // remember that destroy_deck should
  // free all cards present in the
  // deck as well!
  // at this point in the test, the
  // deck should have no cards in it
  // which means this should be
  // equivalent to free(deck).
  destroyDeck(deck);

  end_test();
}

void test_push_card_to_deck()
{
  start_test("push_card_to_deck");

  Deck *deck = createDeck();

  Card card1 = {NINE, HEARTS, -1};
  int top = deck->topCard; 

  pushCardToDeck(&card1, deck);
  top += 1; 
  assert(deck->cards[0] == &card1);
  // The index pointing at the top card should increment by 1
  assert(deck->topCard == top);

  Card card2 = {JACK, CLUBS, -1};

  pushCardToDeck(&card2, deck);
  top += 1; 
  assert(deck->cards[0] == &card1);
  assert(deck->cards[1] == &card2);
  assert(deck->topCard == top);

  Card card3 = {ACE, SPADES, -1};

  int i = 2;
  for(; i < NUM_CARDS_IN_DECK; i++) {
    pushCardToDeck(&card3, deck);
    top += 1; 
    assert(deck->topCard == top);
  }

  for(i = 2; i < NUM_CARDS_IN_DECK; i++) {
    assert(deck->cards[i] == &card3);
  }

  Card card4 = {QUEEN, DIAMONDS, -1};
  pushCardToDeck(&card4, deck);

  assert(deck->cards[0] == &card1);
  assert(deck->cards[1] == &card2);
  assert(deck->cards[NUM_CARDS_IN_DECK - 1] == &card3);

  // not calling destroyDeck here because cards are on stack.
  // I'm just calling free instead.
  free(deck);

  end_test();
}

void test_populate_deck()
{
  start_test("populate_deck");

  int is_deck_populated = 0;
  int i = 0;
  Suit s = HEARTS;
  Name n = NINE;

  Deck *deck = populateDeck();
  

  // deck should be populated in order
  // and not shuffled at this stage
  // If this test is failing for you, 
  // there's a more efficient way to populate 
  // your deck :) 
  for(; s <= DIAMONDS; s++) {
    for(; n <= ACE; n++) {
      assert(deck->cards[i]->suit == s);
      assert(deck->cards[i++]->name == n);
    }
  }

  // just to reiterate...
  // i'm hoping your destroy deck function will
  // first destroy the cards within it too.
  // if not, then there's a memory leak!
  destroyDeck(deck);

  end_test();
}

void test_peek_at_top_card()
{
  start_test("peek_at_top_deck");

  Deck *emptyDeck = createDeck(); 

  //empty deck peek should return NULL
  assert(peekAtTopCard(emptyDeck) == NULL);
  free(emptyDeck)  ;

  Deck *deck = populateDeck();


  Card last_card = {ACE, DIAMONDS, -1};


  assert(peekAtTopCard(deck)->name == last_card.name);
  assert(peekAtTopCard(deck)->suit == last_card.suit);

  destroyDeck(deck);

  deck = createDeck();
  pushCardToDeck(&last_card, deck);

  assert(peekAtTopCard(deck)->name == last_card.name);
  assert(peekAtTopCard(deck)->suit == last_card.suit);

  Card another_card = {TEN, CLUBS, -1};
  pushCardToDeck(&another_card, deck);

  assert(peekAtTopCard(deck)->name == another_card.name);
  assert(peekAtTopCard(deck)->suit == another_card.suit);

  Card one_more_card = {KING, HEARTS, -1};

  int i = 2;
  for(; i < NUM_CARDS_IN_DECK; i++) {
    pushCardToDeck(&one_more_card, deck);
    assert(peekAtTopCard(deck)->name == one_more_card.name);
    assert(peekAtTopCard(deck)->suit == one_more_card.suit);
  }

  // this card should not be pushed since deck is full at this point
  pushCardToDeck(&last_card, deck);
  // peek should show me the last card that was pushed before
  // deck became full
  assert(peekAtTopCard(deck)->name == one_more_card.name);
  assert(peekAtTopCard(deck)->suit == one_more_card.suit);

  free(deck);

  end_test();
}

void test_pop_card_from_deck()
{
  start_test("pop_card_from_deck");

  Deck *deck = createDeck();

  // pop() from empty deck should return NULL
  assert(popCardFromDeck(deck) == NULL);

  Card card1 = {QUEEN, DIAMONDS, -1};
  pushCardToDeck(&card1, deck);

  assert(popCardFromDeck(deck) == &card1);

  Card card2 = {TEN, CLUBS, -1};
  pushCardToDeck(&card1, deck);
  pushCardToDeck(&card2, deck);

  assert(popCardFromDeck(deck) == &card2);

  assert(popCardFromDeck(deck) == &card1);

  free(deck);

  end_test();
}

void test_is_deck_empty()
{
  start_test("is_deck_empty");

  Deck *deck = createDeck();
  assert(isDeckEmpty(deck));

  Card card1 = {QUEEN, SPADES, -1};

  pushCardToDeck(&card1, deck);
  assert(!isDeckEmpty(deck));

  pushCardToDeck(&card1, deck);
  assert(!isDeckEmpty(deck));

  popCardFromDeck(deck);
  assert(!isDeckEmpty(deck));

  popCardFromDeck(deck);
  assert(isDeckEmpty(deck));

  destroyDeck(deck);

  end_test();
}

void test_shuffle()
{
  start_test("test_shuffle");

  end_test();
}

void test_add_card_to_hand()
{
  start_test("add_card_to_hand");

  Hand hand;
  memset(&hand, 0, sizeof(Hand));

  Card card1 = {NINE, HEARTS, -1};
  addCardToHand(&card1, &hand);

  assert(hand.num_cards_in_hand == 1);
  assert(hand.firstCard->thisCard == &card1);
  assert(hand.firstCard->nextCard == NULL);
  assert(hand.firstCard->prevCard == NULL);

  Card card2 = {TEN, CLUBS, -1};
  addCardToHand(&card2, &hand);

  assert(hand.num_cards_in_hand == 2);
  assert(hand.firstCard->nextCard->thisCard == &card1);
  assert(hand.firstCard->nextCard->prevCard->thisCard == &card2);
  assert(hand.firstCard->nextCard->nextCard == NULL);
  assert(hand.firstCard->thisCard == &card2);
  assert(hand.firstCard->prevCard == NULL);

  free(hand.firstCard->nextCard);
  free(hand.firstCard);

  end_test();
}

void test_remove_card_from_hand()
{
  start_test("remove_card_from_hand");

  Hand hand;
  memset(&hand, 0, sizeof(Hand));

  Card card1 = {NINE, HEARTS, -1};
  Card card2 = {TEN, CLUBS, -1};
  Card card3 = {JACK, SPADES, -1};

  addCardToHand(&card1, &hand);
  // remove only card
  removeCardFromHand(&card1, &hand);

  assert(hand.num_cards_in_hand == 0);
  assert(hand.firstCard == NULL);

  addCardToHand(&card1, &hand);
  addCardToHand(&card2, &hand);
  // remove last card
  removeCardFromHand(&card1, &hand);

  assert(hand.num_cards_in_hand == 1);
  assert(hand.firstCard->thisCard == &card2);
  assert(hand.firstCard->nextCard == NULL);
  assert(hand.firstCard->prevCard == NULL);

  addCardToHand(&card1, &hand);
  // remove first card
  removeCardFromHand(&card1, &hand);

  assert(hand.num_cards_in_hand == 1);
  assert(hand.firstCard->thisCard == &card2);
  assert(hand.firstCard->nextCard == NULL);
  assert(hand.firstCard->prevCard == NULL);

  removeCardFromHand(&card2, &hand);
  assert(hand.num_cards_in_hand == 0);
  assert(hand.firstCard == NULL);

  addCardToHand(&card1, &hand);
  addCardToHand(&card2, &hand);
  addCardToHand(&card3, &hand);
  // remove middle card
  removeCardFromHand(&card2, &hand);

  assert(hand.firstCard->nextCard->thisCard == &card1);
  assert(hand.firstCard->nextCard->prevCard->thisCard == &card3);
  assert(hand.firstCard->nextCard->nextCard == NULL);
  assert(hand.firstCard->thisCard == &card3);
  assert(hand.firstCard->prevCard == NULL);

  removeCardFromHand(&card3, &hand);
  removeCardFromHand(&card1, &hand);

  end_test();
}

void test_deal()
{
  start_test("deal");

  Deck *deck = populateDeck();
  shuffle(deck);

  Card *expected_hand1[NUM_CARDS_IN_HAND] = {deck->cards[NUM_CARDS_IN_DECK - 1],
                                             deck->cards[NUM_CARDS_IN_DECK - 3],
                                             deck->cards[NUM_CARDS_IN_DECK - 5],
                                             deck->cards[NUM_CARDS_IN_DECK - 7],
                                             deck->cards[NUM_CARDS_IN_DECK - 9]};

  Card *expected_hand2[NUM_CARDS_IN_HAND] = {deck->cards[NUM_CARDS_IN_DECK - 2],
                                             deck->cards[NUM_CARDS_IN_DECK - 4],
                                             deck->cards[NUM_CARDS_IN_DECK - 6],
                                             deck->cards[NUM_CARDS_IN_DECK - 8],
                                             deck->cards[NUM_CARDS_IN_DECK - 10]};

  Hand hand1;
  memset(&hand1, 0, sizeof(Hand));

  Hand hand2;
  memset(&hand2, 0, sizeof(Hand));

  deal(deck, &hand1, &hand2);

  CardNode *ptr = hand1.firstCard;
  int i = 4;

  while(ptr != NULL) {
    assert(ptr->thisCard == expected_hand1[i]);
    ptr = ptr->nextCard;
    i--;
  }

  ptr = hand2.firstCard;
  i = 4;

  while(ptr != NULL) {
    assert(ptr->thisCard == expected_hand2[i]);
    ptr = ptr->nextCard;
    i--;
  }

  ptr = hand1.firstCard;

  while(ptr != NULL) {
    CardNode *next = ptr->nextCard;
    free(ptr);
    ptr = next;
  }

  ptr = hand2.firstCard;

  while(ptr != NULL) {
    CardNode *next = ptr->nextCard;
    free(ptr);
    ptr = next;
  }

  end_test();
}

void test_is_legal_move()
{
  start_test("is_legal_move");

  Hand hand;
  memset(&hand, 0, sizeof(Hand));

  Card card1 = {QUEEN, HEARTS, -1};
  Card card2 = {KING, SPADES, -1};
  Card card3 = {NINE, CLUBS, -1};
  Card card4 = {NINE, HEARTS, -1};

  addCardToHand(&card1, &hand);
  addCardToHand(&card2, &hand);
  addCardToHand(&card3, &hand);
  addCardToHand(&card4, &hand);

  Card led_card1 = {TEN, HEARTS, -1};

  assert(isLegalMove(&hand, &led_card1, &card1));
  assert(!isLegalMove(&hand, &led_card1, &card2));
  assert(!isLegalMove(&hand, &led_card1, &card3));
  assert(isLegalMove(&hand, &led_card1, &card4));

  Card led_card2 = {JACK, DIAMONDS, -1};

  assert(isLegalMove(&hand, &led_card2, &card1));
  assert(isLegalMove(&hand, &led_card2, &card2));
  assert(isLegalMove(&hand, &led_card2, &card3));
  assert(isLegalMove(&hand, &led_card2, &card4));

  removeCardFromHand(&card1, &hand);
  removeCardFromHand(&card2, &hand);
  removeCardFromHand(&card3, &hand);
  removeCardFromHand(&card4, &hand);

  end_test();
}

void test_who_won()
{
  start_test("create_deck");

  Card card1 = {QUEEN, HEARTS, -1};
  Card card2 = {KING, SPADES, -1};
  Card card3 = {NINE, CLUBS, -1};
  Card card4 = {NINE, HEARTS, -1};

  assert(!whoWon(&card1, &card2, SPADES));
  assert(!whoWon(&card4, &card1, CLUBS));
  assert(whoWon(&card1, &card4, HEARTS));
  assert(whoWon(&card4, &card2, HEARTS));
  assert(!whoWon(&card1, &card3, CLUBS));

  end_test();
}

void test_get_best_move()
{
  start_test("get_best_move");
  end_test();
}

void test_sort_hand()
{
  start_test("sort_hand");
  end_test();
}

void test_shuffle_hand()
{
  start_test("shuffle_hand");
  end_test();
}

int main(void)
{
  srand(21774);

  test_create_deck();
  test_push_card_to_deck();
  test_populate_deck();
  test_peek_at_top_card();
  test_pop_card_from_deck();
  test_is_deck_empty();
  test_shuffle();
  test_add_card_to_hand();
  test_remove_card_from_hand();
  test_deal();
  test_is_legal_move();
  test_who_won();
  test_get_best_move();
  test_sort_hand();
  test_shuffle_hand();

  return EXIT_SUCCESS;
}

