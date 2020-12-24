#include "cards.h"
#include "stdio.h"
#include "assert.h"
int main(void) {
    card_t c; 

    c.value = VALUE_ACE;
    c.suit = SPADES; 
    assert_card_valid(c);

    hand_ranking_t ranking;
    ranking = STRAIGHT_FLUSH;
    printf("%s\n", ranking_to_string(ranking));

    assert(value_letter(c) == 'A');
    assert(suit_letter(c) == 's');

    for(int i = 0; i < 52 ;i++)
    {
        card_t card = card_from_num(i); 
        print_card(card);
        card_t other = card_from_letters(value_letter(card),suit_letter(card));
        print_card(other);
        assert(card.value == other.value && card.suit == other.suit);
        printf("\n");
    }

}
