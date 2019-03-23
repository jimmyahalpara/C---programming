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
    test_d.n_cards = d -> n_cards -i - 1;
    assert( deck_contains(&test_d, **ptr_c) == 0);
    ptr_c++;
  }
}
