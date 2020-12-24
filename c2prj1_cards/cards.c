#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

int check_card(int value, int suit)
{
    return  value >= 2 && value <= 14 && suit >= SPADES && suit <= CLUBS; 
}

void assert_card_valid(card_t c) {
    assert(check_card(c.value, c.suit));
}

/*- const char * ranking_to_string(hand_ranking_t r);
  This function should convert the
  hand_ranking_t enumerated value passed
  in to a string that describes it.  Remember
  that Drew showed you a nice way to do this
  with emacs keyboard macros!*/


const char * ranking_to_string(hand_ranking_t r) {
    switch(r)
    {
        case STRAIGHT_FLUSH:
            return "STRAIGHT_FLUSH";
        case FOUR_OF_A_KIND:
            return "FOUR_OF_A_KIND";
        case FULL_HOUSE:
            return "FULL_HOUSE";
        case FLUSH:
            return "FLUSH";
        case STRAIGHT:
            return "STRAIGHT";
        case THREE_OF_A_KIND:
            return "THREE_OF_A_KIND";
        case TWO_PAIR:
            return "TWO_PAIR";
        case PAIR:
            return "PAIR";
        default:
            return "NOTHING";
    }
}
/*  This function should return the character that textually represents
    the value of the passed-in card.  For values 2-9, this should
    be that digit.  For 10, it should be '0', and for Jack, Queen, King, and Ace,
    it should be 'J', 'Q', 'K', and 'A' respectively.
Hint: remember everything is a number.
For example, the character '0' has the decimal value 48,
and the character '5' has the decimal value 53, so you could represent
'5' as '0' + 5.*/


char value_letter(card_t c) {
    assert_card_valid(c);
    if(c.value >=2 && c.value <=9)
    {
        return '0' + c.value;
    }
    else if( c.value == 10)
    {
        return '0';
    }
    else 
    {
        switch(c.value)
        {
            case VALUE_ACE:
                return 'A';
            case VALUE_KING:
                return 'K';
            case VALUE_QUEEN:
                return 'Q';
            case VALUE_JACK:
                return 'J';	 
            default:
                return '?';	
        }
    }

}


char suit_letter(card_t c) {
    assert_card_valid(c);
    switch(c.suit)
    {
        case SPADES:
            return 's';
        case DIAMONDS:
            return 'd';
        case CLUBS:
            return 'c';
        case HEARTS:
            return 'h';	
        default:
            return '0' + c.suit;	
    }
}

void print_card(card_t c) {
    printf("%c%c",value_letter(c),suit_letter(c));
}
/*card_t card_from_letters(char value_let, char suit_let);
  This function should make and return a
  card_t whose value and suit correspond
  to the letters passed in. If the values passed
  in are invalid, you should use assert()
  or print an error messa$ge and exit(EXIT_FAILURE)*/


card_t card_from_letters(char value_let, char suit_let) {

    card_t temp;

    switch(suit_let)
    {
        case 's':
            temp.suit = SPADES;
            break;
        case 'd': 
            temp.suit = DIAMONDS;
            break;
        case 'c':
            temp.suit = CLUBS; 
            break;
        case 'h': 
            temp.suit = HEARTS; 
            break;
        default:
            temp.suit = NUM_SUITS; 
    }

    if(value_let >= '2' && value_let <= '9')
    {
        temp.value = value_let - '0';
    }
    else if(value_let  == '0' )
    {
        temp.value = 10;
    }
    else 
    {
        switch(value_let)
        {
            case 'A': 
                temp.value = VALUE_ACE; 
                break;
            case 'K': 
                temp.value = VALUE_KING; 
                break;
            case 'Q': 
                temp.value = VALUE_QUEEN;
                break;
            case 'J': 
                temp.value = VALUE_JACK; 
                break;
            default:
                temp.value = -1;
        }
    }

    assert_card_valid(temp); 
    return temp;
}
/* card_t card_from_num(unsigned c);
   This function should take a number from 0 (inclusive)
   to 52 (exclusive) and map it uniquely to
   a card value/suit combination.  Exactly
   how you map the numbers to values/suits
   is up to you, but you must guarantee
   that each valid value/suit combination
   corresponds to exactly one input value
   in the range [0,52). Hint: you may want to use the mod
   operator % to find the remainder of a number divided by 13.
   (In Course 3, this function will be used
   to make a deck of cards by iterating
   over that range and calling it once
   for each value--you just need
   to learn about arrays first so you
   have a place to put all those
   cards.)*/

card_t card_from_num(unsigned c) {
    char value = c / 4;
    char suit = c % 4; 
    card_t card;
    card.value = value + 2;
    card.suit = suit;
    assert_card_valid(card); 
    return card; 
}
