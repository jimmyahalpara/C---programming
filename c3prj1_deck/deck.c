#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  card_t **card = hand -> cards;
  for (int i = 0; i < hand -> n_cards; i++){
    print_card(**card);
    printf(" ");
    card++;
  }
}

int deck_contains(deck_t * d, card_t c) {
  card_t **card = d -> cards;
  for (int i = 0; i < d -> n_cards; i++){
    if ((**card).suit == c.suit && (**card).value == c.value){
	return 1;
      }
    card++;
  }
  return 0;
}

void shuffle(deck_t * d){
  if (d -> n_cards < 2){return;}
  card_t **card = d -> cards;
  card_t * temp;
  size_t n = d -> n_cards;
  int randarry;
  for (size_t i = 0; i < n/2; i++){
    randarry = random()%(n - i) + i;
    temp = card[i];
    card[i] = card[randarry];
    card[randarry] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  card_t ** ptr_c = d -> cards;
  deck_t test_d;
  for (int i = 0; i < d -> n_cards - 1; i++){
    test_d.cards = d -> cards + i + 1;
    test_d.n_cards = d -> n_cards - i - 1;
    assert( deck_contains(&test_d, **ptr_c) == 0);
    ptr_c++;
  }
}

void add_card_to(deck_t * deck, card_t c){
  card_t* c1 = malloc(sizeof(*c1));
  c1 -> value = c.value;
  c1 -> suit = c.suit;
  deck -> cards =realloc(deck -> cards, (deck -> n_cards + 1)* sizeof(*deck -> cards));
  deck -> cards[deck -> n_cards] = c1;
  deck -> n_cards ++;
}

card_t * add_empty_card(deck_t * deck){
  card_t * c1 = malloc(sizeof(*c1));
  c1 -> value = 0;
  c1 -> suit = 0;
  deck -> cards = realloc(deck -> cards, (deck -> n_cards + 1) * sizeof(*deck -> cards));
  deck -> cards[deck -> n_cards] = c1;
  deck -> n_cards ++;
  return c1;
}

deck_t * make_deck_exclude(deck_t * excluded_cards){
  deck_t* ans = malloc(sizeof(*ans));
  ans -> cards = NULL;
  ans -> n_cards = 0;
  for (unsigned i = 0; i < 52; i++){
    card_t c = card_from_num(i);
    if (!deck_contains(excluded_cards,c)) add_card_to(ans,c);
  }
  return ans;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
  deck_t * deck = malloc(sizeof(*deck));
  deck -> n_cards = 0;
  deck -> cards = NULL;
  for (size_t i = 0; i < n_hands ; i++){
    for (int x = 0; x < hands[i] -> n_cards; x++){
    deck -> cards = realloc(deck -> cards, (deck -> n_cards + 1) * sizeof(*deck ->cards));
    deck -> cards[deck -> cards] = hands[i] -> cards[x];
    deck -> n_cards ++;
  }
}
  deck_t* deck2 = make_deck_exclude(deck);
  free(deck -> cards);
  free(deck);
  return deck2;
}

void free_deck(deck_t * deck){
  for (int i = 0; i < deck -> n_cards; i++){
    free(deck -> cards[i]);
  }
  free(deck -> cards);
  free(deck);
}
