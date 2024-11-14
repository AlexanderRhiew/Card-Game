//Alex Rhiew + Taysom StolWorthy
//12/6/2024
//Card_Game
//Poker Variation, decks. 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct card_S {
    char suit;
    int rank;

 } card;
/* 36 element array of card element
array of Hearts, Diamonds, Spades, and Clubs
Count = 0
loop to assign the suit (4 iterations)
    loop to assign the rank (9 iterations) 
    array[count].suit
    array[count].rank


void card_suit {

}

void card_rank {

}

void printfct {

}

void shuffle_deck {

}


*/
int main(void) {
    int test, i, c_count, coins_entered, faces;
    int coins = 100;
    printf("Enter an amount of coins to start playing: ");
    scanf("%d", &coins_entered);
    if ((coins_entered <= 0) || (coins_entered > 100)) {
        printf("Game is over.");
        return -1;

    }
    printf("You have been dealt 5 cards.")

    int card[36]


    
    return 0;
}
