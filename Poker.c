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


void card_suit {card_s[]};

}

void card_rank {

}

void printfct {

}

void shuffle_deck {

}
void deal_card {
int i, hand = 5;
for (i = 0; i < hand; i++) {
    randint(CallNum);
    hand++;
}

*/
void CallNum(card list[], int num){
  int i = 1; 
  int track = 0; 
  char select; 

      while(track < num) {
          if(i == 10) {
              i = 1; 
             }
          if(select = 4) {
            club = 'club';

          }
   // list[]
    list[track].rank = i; 
    list[track].suit = select; 
          
          printf("%d\n", list[track].rank); 
          i = i + 1; 
          track = track + 1;
      }
      
  }

int Deal_Card(int i);

int main(void) {

    int i;
    int NumOfPlayers;

    printf("Please Enter the Number Of Players: ");
    scanf("%d", &NumOfPlayers);

    for (i = 1; i <= NumOfPlayers; i++)
    {
        Deal_Card(i);
    }
}
    int i, c_count, coins_entered, faces;
    int coins = 100, hand = 0;
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
        while (hand < 5) {
            deal_card();
            hand++;

        }
        printf("You have been dealt 5 cards.")
    }
    int card[36]


    
    return 0;
}
