//Alex Rhiew + Taysom StolWorthy
//12/6/2024
//Card_Game
//Poker Variation, decks. 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct card_S {
    char suit;
    int rank;

 } card;

void CallNum(card list[], int num){
  int i = 1; 
  int track = 0; 
  char select = 0; 
    while( track < num){
          if(i == 10){
              i = 1; 
              select++; 

             }
        list[track].rank = i; 

        if(select == 0){
        list[track].suit = 'C'; 
      }
       if(select == 1){
        list[track].suit = 'S'; 
      }
       if(select == 2){
        list[track].suit = 'H'; 
      }
       if(select == 3){
        list[track].suit = 'D'; 
      }

       // printf("%d%c\n", list[track].rank, list[track].suit); 
        i = i + 1; 
        track = track + 1;
      }
      
  }
  
  void deal_card(int hand[]){
    int i; 
    srand((int)time(0));
    
    for (int i = 0; i < 5; i++) {
        hand[i] = rand()%35;
        //printf("%d ", hand[i]);
        
    }
}

void printCard(card list[], int i, int hand[]){
    
    printf("%d", list[hand[i]].rank);
    printf("%c ", list[hand[i]].suit);

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


void shuffle_deck {

}
void deal_card {
int i, hand = 5;
for (i = 0; i < hand; i++) {
    randint(CallNum);
    hand++;
}


//nt Deal_Card(int i);
*/
int main(void) {

    int i;
    char name[100];
    int hand[5];
    int store[5];
    printf("Please enter your name:");
    fgets(name, 100, stdin);
    printf("%s", name);
    
    int num = 36; 
    card list[num];
    CallNum(list, num);

   /* for (i = 1; i <= NumOfPlayers; i++) {
        Deal_Card(i);
    }

*/

    int c_count, coins_entered, faces;
    int coins = 100;
    
 
    
    
  
   // printf("%d", list[hand[1]].rank);
   // printf("%c", list[hand[1]].suit);
    
    printf("Enter an amount of coins to start playing: ");
    scanf("%d", &coins_entered);
    if ((coins_entered <= 0) || (coins_entered > 100)) {
        printf("Game is over.");
        return -1;

    }
    else {
        while (i < 5) {
            deal_card(hand);
            ++i;

        }
        printf("You have been dealt 5 cards.\n");
        
    }
    for(i = 0; i < 5; ++i){
       printCard(list, i, hand); 
    }
    
    
    int card[36];


    
    return 0;
}
