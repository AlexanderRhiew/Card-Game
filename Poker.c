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
  
 int deal_card(int hand[], int plays, card list[]){
     int i; 
      for(i = 0; i < 5 ; ++i){
        list[plays].rank;
        list[plays].suit;
        hand[i] = plays; 
        plays++;
      }
return plays;
}

void printCard(card list[], int i, int hand[]){
    
    printf("%d", list[hand[i]].rank);
    printf("%c ", list[hand[i]].suit);

}

void shuffle_deck(card list[]) {
card temp[2];
int swap;
 int i, j; 
 
    srand((int)time(0));
    for(j = 0; j < 4; ++j){
        for (i = 0; i < 36 ; i++){
            swap = rand()%35;
            temp[1].rank = list[i].rank;
            temp[1].suit = list[i].suit;
            
            list[i].rank = list[swap].rank;
            list[i].suit = list[swap].suit; 
            
            list[swap].rank = temp[1].rank;
            list[swap].suit = temp[1].suit;
        }
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
    int plays = 0; 
    printf("Please enter your name:");
    fgets(name, 100, stdin);
    printf("%s", name);
    
    int num = 36; 
    card list[num];
    CallNum(list, num);
    shuffle_deck(list);
    int c_count, coins_entered, faces;
    int coins = 100;
    
   // printf("%d", list[1].rank);
   //printf("%c", list[1].suit);

    printf("Enter an amount of coins to start playing: ");
    scanf("%d", &coins_entered);
    if ((coins_entered <= 0) || (coins_entered > 100)) {
        printf("Game is over.");
        return -1;

    }
    
   plays = deal_card(hand, plays, list);
   
     printf("You have been dealt 5 cards.\n");
        
   // printf("%d ", plays);
    
    for(i = 0; i < 5; ++i){
       printCard(list, i, hand); 
    }


    
    return 0;
}
