#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= 14);
  assert(c.suit == SPADES || c.suit == CLUBS || c.suit == DIAMONDS || c.suit == HEARTS);
}

const char * ranking_to_string(hand_ranking_t r) {
  if (r == STRAIGHT_FLUSH){
    return "STRAIGHT_FLUSH";
  }
  else if (r == FOUR_OF_A_KIND){
    return "FOUR_OF_A_KIND";
  }
  else if (r == FULL_HOUSE){
    return "FULL_HOUSE";
  }
  else if (r == FLUSH){
    return "FLUSH";
  }
  else if (r == STRAIGHT){
    return "STRAIGHT";
  }
  else if (r == THREE_OF_A_KIND){
    return "THREE OF_A_KIND";
  }
  else if (r == TWO_PAIR){
    return "TWO_PAIR";
  }
  else if (r == PAIR){
    return "PAIR";
  }
  else if  (r == NOTHING){
    return "NOTHING";
  }
  else {
    return "INVALID";
  }
}

char value_letter(card_t c) {
  if (c.value >= 2 && c.value <= 9){
    return '0' + c.value;
  }
  else if (c.value == 10){
    return '0';
  }
  else if (c.value == 13){
    return 'K';
  }
  else if (c.value == 12){
    return 'Q';
  }
  else if (c.value == 11){
    return 'J';
  }
  else if (c.value == 14){
    return 'A';
  }
  else {
    return '-';
  }
}


char suit_letter(card_t c) {
  if (c.suit == SPADES){
    return 's';
  }
  else if (c.suit == HEARTS){
    return 'h';
  }
  else if (c.suit == DIAMONDS){
    return 'd';
  }
  else if (c.suit == CLUBS){
    return 'c';
  }
  else {
    return '-';
  }
  
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if (value_let == 'A'){
    temp.value = 14;
  }
  else if (value_let == 'K'){
    temp.value = 13;
  }
  else if (value_let == 'Q'){
    temp.value = 12;
  }
  else if (value_let == 'J'){
    temp.value = 11;
  }
  else if (value_let == '0'){
    temp.value = 10;
  }
  else if (value_let == '9'){
    temp.value = 9;
  }
  else if (value_let == '8'){
    temp.value = 8;
  }
  else if (value_let == '7'){
    temp.value = 7;
  }
  else if (value_let == '6'){
    temp.value = 6;
  }
  else if (value_let == '5'){
    temp.value = 5;
  }
  else if (value_let == '4'){
    temp.value = 4;
  }
  else if (value_let == '3'){
    temp.value = 3;
  }
  else if (value_let == '2'){
    temp.value = 2;
  }
  if (suit_let == 's'){
    temp.suit = SPADES;
  }
  else if (suit_let == 'h'){
    temp.suit = HEARTS;
  }
  else if (suit_let == 'd'){
    temp.suit = DIAMONDS;
  }
  else if (suit_let == 'c'){
    temp.suit = CLUBS;
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  unsigned v = c%13+2;
  card_t crd;
  crd.value = v;
  char value_l = value_letter(crd);
  unsigned su = c/13;
  char sl;
  if (su == 0){
    sl = 's';
  }
  else if (su == 1){
    sl = 'h';
  }
  else if (su == 2){
    sl = 'd';
  }
  else if (su == 3){
    sl = 'c';
  }
  temp = card_from_letters(value_l, sl);
  return temp;
}
