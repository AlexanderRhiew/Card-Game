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

void printCard(card list[], int hand[]){
    int i; 
        for(i = 0; i < 5; ++i){
        printf("%d", list[hand[i]].rank);
        printf("%c ", list[hand[i]].suit);
    }
    printf("\n");
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

int kind(card list[], int hand[], int condition){
    int i,j;
    int check; 
    int most_matches = 0;
    for(j = 0; j < 5; j++){
        check = 0; 
        for(i = 0; i < 5; i++){
                if(list[hand[i]].rank == list[hand[j]].rank){
                    check++; 
                } 
            }
        if(check > most_matches){
            most_matches = check;
        }
    }
    if(most_matches == 3){
        condition = 6;
    }
    if(most_matches == 4){
        condition = 2;
    }
        return condition; 
}


int flush(card list[], int hand[], int condition){
    int check; 
    int i; 
        for(i = 0; i < 5; i++){
            if(list[hand[i]].rank == list[hand[i]].rank + i){
                check++; 
            } 
        }
        
    if(check == 5){ 
        condition = 1; 
    }
    else{
        condition = 4; 
    }
    
    return condition; 
    }

void play(card list[], int hand[]){
int i;
int check = 0; 
int condition; 

    condition = kind(list, hand, condition);
    for(i = 0; i < 5; i++){
        if(list[hand[i]].suit == list[hand[0]].suit){
            check++;
        }
    }
    if(check == 5){
       condition = flush(list, hand, condition);
        }
    if(condition == 1){
        printf("Royal Flush");
    }
    if(condition == 2){
        printf("4 of a kind");
    }
    
    if(condition == 4){
        printf("Flush");
    }
    if(condition == 6){
        printf("3 of a kind");
    }
}



    
/*
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
    
    
   // printf("%d", list[1].rank);
   //printf("%c", list[1].suit);
   
    int c_count, coins_entered, faces;
    int coins = 100;

    printf("Enter an amount of coins to start playing: ");
    scanf("%d", &coins_entered);
    if ((coins_entered <= 0) || (coins_entered > 100)) {
        printf("Game is over.");
        return -1;

    }
    
   plays = deal_card(hand, plays, list);
   
   printf("You have been dealt 5 cards.\n");
        
    //printf("%d ", plays);
    
    printCard(list, hand); 
    
while(num != -1){
    printf("Enter card 1-5 to change or -1 to stop:");
    scanf("%d", &num);
        if(num > 0 && num < 6){
        hand[num-1] = plays + 1;
        plays = hand[num-1];
    }
}

printCard(list, hand); 

play(list, hand);

    return 0;
}
