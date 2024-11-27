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
 
 void sort(int hand[], card list[]){
 int i;
 int j; 
 int temp;


    for(i = 0; i < 5; i++){
    j = i;
        while(j > 0 && (list[hand[j]].rank < list[hand[j-1]].rank)){
           temp = hand[j-1];
          hand[j-1] = hand[j];
           hand[j] = temp; 
           --j;
        }
    }
}


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
    int i, j;
    int check; 
    int most_matches = 0;
    int second_matches; 
    
    for(j = 0; j < 5; j++){
        check = 0; 
        for(i = 0; i < 5; i++){
                if(list[hand[i]].rank == list[hand[j]].rank){
                    check++; 
                } 
            }
        if(check > most_matches){
            second_matches = most_matches;
            most_matches = check;
            
            
        }
    }
    
    if(most_matches == 3){
        if(second_matches == 2){
            condition = 3;
        }
        else{
            condition = 6;
        }
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
            if(list[hand[i]].rank == list[hand[0]].rank + i){
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

int straight(int hand[], card list[], int condition){
    int check = 0; 
    int i; 
        for(i = 0; i < 5; i++){
            if(list[hand[i]].rank == list[hand[0]].rank + i){
                check++; 
            } 
        }
        
    if(check == 5){ 
        condition = 5; 
    }
    return condition;
}


int play(card list[], int hand[]){
int i, j;
int check = 0; 
int condition = 0; 
int keep = 0; 
int wins = 0; 
condition = straight(hand, list, condition);
condition = kind(list, hand, condition);
    
for(j = 0; j < 5; j++){
    check = 0; 
    for(i = 0; i < 5; i++){
        if(list[hand[i]].suit == list[hand[j]].suit){
            check++;
        }
    }
    if(check > keep){
        keep = check; 
    }
}
    if(check == 5){
       condition = flush(list, hand, condition);
        }
        
    if(condition == 1){
        printf("Royal Flush\n");
        wins = 100; 
    }
    if(condition == 2){
        printf("4 of a kind\n");
        wins = 50;
    }
    if(condition == 3){
        printf("Full House\n"); //check
        wins = 20;
    }
    
    if(condition == 4){
        printf("Flush\n");
        wins = 15;
    }
    if(condition == 5){ 
        printf("Straight\n"); 
        wins = 10;
    }
    if(condition == 6){
        printf("3 of a kind\n");
        wins = 3; 
    }
    
return wins;
}


int main(void) {

    int i, wins;
    wins = 0; 
    char name[100];
    int hand[5];
    int store[5];
    int plays = 0; 
    
    printf("Please enter your name:");
    fgets(name, 100, stdin);
    if(name[strlen(name) - 1] == '\n'){
        name[strlen(name) - 1] = '\0';
    }
        
    
    
    
    int num = 36; 
    card list[num];
     CallNum(list, num);
     shuffle_deck(list);
    int con = 0; 
    int coins = 100;
    while(con != -1){
  
    if(plays > 25){
        shuffle_deck(list);
        plays = 0; 
    }
    
   // printf("%d", list[1].rank);
   //printf("%c", list[1].suit);
   
    int c_count, coins_entered, faces;
    int skip = 0; 
    
    printf("%s has %d coins\n", name, coins);
    
    while(skip != 1){
        printf("Please enter an amount of coins to start playing: ");
        scanf("%d", &coins_entered);
         
        if ((coins_entered > 0) && (coins_entered <= coins)) {
            skip = 1; 
    
        }
    }
    
    coins = coins - coins_entered; 
    
   plays = deal_card(hand, plays, list);
   
   printf("You have been dealt 5 cards.\n");
        
    //printf("%d ", plays);
   
    sort(hand, list);
    printCard(list, hand); 
int swap = 0; 
while(swap != -1){
    printf("Enter card 1-5 to change or -1 to stop:");
    scanf("%d", &swap);
        if(swap > 0 && swap < 6){
        hand[swap-1] = plays + 1;
        plays = hand[swap-1];
    }
}
 
sort(hand, list);
printCard(list, hand); 

wins = play(list, hand);

c_count = wins * coins_entered; 
coins = coins + c_count; 
printf("you have %d coins\n", coins);
if(coins <= 0){
printf("You lose");
break; 
}
printf("Continue? (-1 to quit):\n\n");
scanf("%d", &con);

}

    return 0;
}
