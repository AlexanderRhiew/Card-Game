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

void CallNum(card list[], int num){
  int i = 1; 
  int track = 0; 
  char select; 
      while( track < num){
          if(i == 10){
              i = 1; 
             }
          if(select = )
   // list[]
    list[track].rank = i; 
    list[track].suit = select; 
          
          printf("%d\n", list[track].rank); 
          i = i + 1; 
          track = track + 1;
      }
      
  }

/* 36 element array of card element
array of Hearts, Diamonds, Spades, and Clubs
Count = 0
loop to assign the suit (4 iterations)
    loop to assign the rank (9 iterations) 
    array[count].suit
    array[count].rank


void card_suit {card_s[]};

}

void card_rank {

}

void printfct {

}

void shuffle_deck {

}


*/
int main(void) {
    int i, c_count, coins_entered, faces;
    int coins = 100;
    for (int i = 0; i > 5; i++) {
        srand((int)time(0));
        int num = rand()%35;
        printf("%d", num);
    }

    int num = 36; 
    card list[num];
    CallNum(list, num);
    
    printf("Enter an amount of coins to start playing: ");
    scanf("%d", &coins_entered);
    if ((coins_entered <= 0) || (coins_entered > 100)) {
        printf("Game is over.");
        return -1;

    }
    else {
        printf("You have been dealt 5 cards.")
    }
    int card[36]


    
    return 0;
}
