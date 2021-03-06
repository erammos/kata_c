#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
	for(int i = 0; i < hand->n_cards;i++)
	{
		print_card(*hand->cards[i]);
	}
}

int deck_contains(deck_t * d, card_t c) {

	for(int i = 0; i < d->n_cards;i++)
	{
		if(d->cards[i]->value == c.value && d->cards[i]->suit == c.suit)
		{
			return 1;
		}
	}


	return 0;
}

void shuffle(deck_t * d){

	for(int i = 0; i < d->n_cards;i++)
	{

		int index = random() % d->n_cards;
		card_t* temp = d->cards[i];
		d->cards[i] = d->cards[index];
		d->cards[index] = temp;

	}
}

void assert_full_deck(deck_t * d) {
	for(int i = 0 ; i < d->n_cards; i++)
	{
               
		for(int j = i + 1; j < d->n_cards; j++)
		{
			card_t c = *d->cards[j];
			assert(!(d->cards[i]->value == c.value && d->cards[i]->suit == c.suit));

		}
	}
}
