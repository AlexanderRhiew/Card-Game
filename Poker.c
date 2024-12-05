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
 
 void sort(int hand[], card list[]){. //Function will sort each card by numeric value
 int i;                             //least to greatest
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


void CallNum(card list[], int num){ //function is to fill array of type card for both the suit and rank
  int i = 1;                        //there will be 36 cards in total  
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
  
 int deal_card(int hand[], int plays, card list[]){ //This is to deal the card to the player
     int i;                                         //array hand refers to what's in your hand 
      for(i = 0; i < 5 ; ++i){                      //hand will equal to a plays integer  
        list[plays].rank;                           //plays is the position the card sits in the card array
        list[plays].suit;                           //returns the new play value
        hand[i] = plays; 
        plays++;
      }
      
return plays;
}

void printCard(card list[], int hand[]){ //simply prints the cards in your hand
    int i; 
        for(i = 0; i < 5; ++i){
        printf("%d", list[hand[i]].rank);
        printf("%c ", list[hand[i]].suit);
    }
    printf("\n");
}


void shuffle_deck(card list[]) { //shuffles deck with random numbers under 35
card temp[2];                   // the card value at random number will be swap 
int swap;                       //with the value of i in a for loop that repeats 4
 int i, j;                      //times
 
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

int kind(card list[], int hand[], int condition){ //this checks if your hand is either
    int i, j;                                     // a full house, a 3 in a row, or a
    int check = 0;                                // 4 in a row. 
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
        if(second_matches == 2){ //if we have 3 cards of the same value plus 2 cards
            condition = 3;      //cards of the same value, then we got a house. 
        }                       
        else{.           //otherwise it's just 3 in a row
            condition = 6;
        }
    }
    
    if(most_matches == 4){ //4 in a row
        condition = 2;
    }
        return condition; //conditions go into the play function
}


int flush(card list[], int hand[], int condition){ //function is for hands with cards of the same suit
    int check = 0; 
    int i; 
        for(i = 0; i < 5; i++){ 
            if(list[hand[i]].rank == list[hand[0]].rank + i){
                check++;    //since the hand is already sorted least to greatest
            }               //we can just check hand[i]'s position compared to hand[0];
        }
        
    if(check == 5){  //straight flush
        condition = 1; 
    }
    else{.     //otherwise it's just a normal flush 
        condition = 4; 
    }
    
    return condition;  //returns to the play function
    }

int straight(int hand[], card list[], int condition){
    int check = 0; 
    int i; 
        for(i = 0; i < 5; i++){ //same to the flush function, but for hands with different suits cards. 
            if(list[hand[i]].rank == list[hand[0]].rank + i){
                check++; 
            } 
        }
        
    if(check == 5){ 
        condition = 5; 
    }
    return condition; //returns to the play function
}



int play(card list[], int hand[]){ //is called in main and will determine if the hand has any win conditions
    
int i, j;
int check = 0; 
int condition = 0; 
int keep = 0; 
int wins = 0; 

condition = straight(hand, list, condition); //checks if it's a straight

condition = kind(list, hand, condition); //checks if it's either full house, 4 of a kind, or 3 of a kind 
    
    
for(j = 0; j < 5; j++){ //checks each card to see if they have the same rank as the other 4 cards
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
       condition = flush(list, hand, condition); //if cards are all the same rank, then check to see if it's a straight
        }
        
    if(condition == 1){
        printf("Straight Flush\n");
        wins = 100; //wins is how much money is mulitply 
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
    
return wins; //returns to main
}


int main(void) {

    int i, wins;
    wins = 0; 
    char name[100];
    int hand[5];
    int store[5];
    int plays = 0; //play value will refer to the position in card list[]
    
    printf("Please enter your name:");
    fgets(name, 100, stdin);
    
    if(name[strlen(name) - 1] == '\n'){
        name[strlen(name) - 1] = '\0';
    }
    //use strlen because otherwise fgets gets funky
    
    
    int num = 36; 
    card list[num];
    CallNum(list, num); //function that assigns the deck 
    shuffle_deck(list); //shuffles the deck
    int con = 0; 
    int coins = 100; //starting number of coins that you have 
    
    while(con != -1){ //stop game once con = -1; 
      
        if(plays > 25){ //once the deck deals over 25 cards, then it will shuffle
            shuffle_deck(list);
            plays = 0; 
        }
        
       
        int c_count, coins_entered, faces;
        int skip = 0; 
        
        printf("%s has %d coins\n", name, coins);
        
        while(skip != 1){ //repeats until you put in a value number of coins
            printf("Please enter an amount of coins to start playing: ");
            scanf("%d", &coins_entered);
             
            if ((coins_entered > 0) && (coins_entered <= coins)) {
                skip = 1; 
        
            }
        }
        
        coins = coins - coins_entered; //you will have this number of coins left if you lose
        
       plays = deal_card(hand, plays, list); //deal_card will move the plays value by +5. 
       
       printf("You have been dealt 5 cards.\n");
            
        sort(hand, list); //sort hand 
        printCard(list, hand); //prints hand.
    int swap = 0; 
    
    while(swap != -1){
        printf("Enter card 1-5 to change or -1 to stop:");
        scanf("%d", &swap);
            if(swap > 0 && swap < 6){
            hand[swap-1] = plays + 1; //array starts a 0, so swap needs to be subtracted by one
            plays = hand[swap-1]; //swaps card with the top card on the deck
        }
    }

     
    sort(hand, list);
    printCard(list, hand); //shows new hand 
    
    wins = play(list, hand); //play function will find if you have any win conditions
                             //then it will assign how much it's worth.
     c_count = wins * coins_entered; //mulitply wins with the amount of coins you entered
        if(wins == 0){
        printf("you lose %d coins \n", coins_entered);
        }
        
        if(wins != 0){
        printf("you win %d coins \n", c_count);
        }
        
    
    coins = coins + c_count; //new amount of coins
    printf("you have %d coins\n", coins);
    
    if(coins <= 0){
        printf("Game over");
        break; //lose game when you have 0 coins
    }
    
    printf("Continue? (-1 to quit):\n\n");
    scanf("%d", &con); //if you still have coins, you can choose to keep playing

}

    return 0;
}
