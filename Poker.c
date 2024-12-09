//Alex Rhiew + Taysom StolWorthy
//12/6/2024
//Card_Game
//Poker Variation, decks.

*UPDATED VERSION CODE: LINES 7-505*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct card_S {
    char suit;
    int rank;

 } card;
 
 void write_statistics_to_file(int total_rounds, int wins, int losses, int hand_wins[]); //Function for statistics
 
 void sort(int hand[], card list[]){ //Function will sort each card by numeric value
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
    printf("\n\n");
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
        else{         //otherwise it's just 3 in a row
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
    else{    //otherwise it's just a normal flush 
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



/*int play(card list[], int hand[]){ //is called in main and will determine if the hand has any win conditions
    
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
        printf("Straight Flush!\n");
        wins = 100; //wins is how much money is mulitply 
    }
    if(condition == 2){
        printf("4 of a kind!\n");
        wins = 50;
    }
    if(condition == 3){
        printf("Full House!\n"); //check
        wins = 20;
    }
    
    if(condition == 4){
        printf("Flush!\n");
        wins = 15;
    }
    if(condition == 5){ 
        printf("Straight!\n"); 
        wins = 10;
    }
    if(condition == 6){
        printf("3 of a kind!\n");
        wins = 3; 
    }
    
return wins; //returns to main
}
*/
int play(card list[], int hand[]) { //Function for determing hand value/worth
    int rank_count[10] = {0};
    int suit_count[4] = {0};

    for (int i = 0; i < 5; ++i) {
        rank_count[list[hand[i]].rank]++;
        switch (list[hand[i]].suit) { //Each case represents either Hearts, Diamonds, Clubs, or Spades
            case 'H': suit_count[0]++; 
            break;
            case 'D': suit_count[1]++; 
            break;
            case 'C': suit_count[2]++; 
            break;
            case 'S': suit_count[3]++; 
            break;
        }
    }

    int flush = 0;
    for (int i = 0; i < 4; ++i) {
        if (suit_count[i] == 5) {
            flush = 1;
            break;
        }
    }

    int straight = 0, consecutive = 0;
    for (int i = 1; i <= 9; ++i) {
        if (rank_count[i] > 0) {
            consecutive++;
            if (consecutive == 5) {
                straight = 1;
                break;
            }
        } 
        else {
            consecutive = 0;
        }
    }

    int pairs = 0, three_of_a_kind = 0, four_of_a_kind = 0;
    for (int i = 1; i <= 9; ++i) {
        if (rank_count[i] == 2) pairs++;
        if (rank_count[i] == 3) three_of_a_kind = 1;
        if (rank_count[i] == 4) four_of_a_kind = 1;
    }

    if (straight && flush) return 1; //Straight Flush
    if (four_of_a_kind) return 2;
    if (three_of_a_kind && pairs == 1) return 3; //Full House
    if (flush) return 4;
    if (straight) return 5;
    if (three_of_a_kind) return 6;
    if (pairs == 2) return 7;
    if (pairs == 1) return 8;
    return 0;
}

char* get_hand_type(int condition) { //Used to print what hand the player has.
    switch(condition) {
        case 1: return "\nStraight Flush!";
        case 2: return "\nFour of a Kind!";
        case 3: return "\nFull House!";
        case 4: return "\nFlush!";
        case 5: return "\nStraight!";
        case 6: return "\nThree of a Kind!";
        case 7: return "\nTwo Pairs!";
        case 8: return "\nOne Pair!";
        default: return "\nBad hand.";
    }
}

char* suggest_cards_to_keep(card list[], int hand[], int condition) {
    static char suggestion[100]; //NEED STATIC in order to prevent function being accessed in other parts and 
    //messing with card prints
    suggestion[0] = '\0';

    if (condition == 1 || condition == 3 || condition == 4 || condition == 5) { //Checks to see if the player meets one of the "good" hands
        //If they do, prints what cards they are recommended to keep
        strcpy(suggestion, "Keep all cards: ");
        for (int i = 0; i < 5; ++i) {
            char card[5];
            sprintf(card, "%d%c ", list[hand[i]].rank, list[hand[i]].suit);
            strcat(suggestion, card);
        }
    } 
    else if (condition == 2 || condition == 6 || condition == 7 || condition == 8) {
        strcpy(suggestion, "Keep: ");
        for (int i = 0; i < 5; ++i) {
            for (int j = i + 1; j < 5; ++j) {
                if (list[hand[i]].rank == list[hand[j]].rank) {
                    char card1[5], card2[5]; //Make 2 sprintf fct to account for
                    //possibilities of multiple pairs in a hand, like 3D 3S 4H 4S 5H
                    sprintf(card1, "%d%c ", list[hand[i]].rank, list[hand[i]].suit);
                    sprintf(card2, "%d%c ", list[hand[j]].rank, list[hand[j]].suit);
                    strcat(suggestion, card1);
                    strcat(suggestion, card2);
                }
            }
        }
    } 
    else {
        strcpy(suggestion, "User decision for card replacement"); //Hand has nothing of value
    }
    return suggestion;
}

void write_statistics_to_file(int total_rounds, int wins, int losses, int hand_wins[]) { //Extra Credit, keeps data aftergame in a separate file
    FILE *file = fopen("game_statistics.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to write statistics to file.\n");
        return;
    }
    fprintf(file, "Game Statistics:\n");
    fprintf(file, "Total Rounds Played: %d\n", total_rounds);
    fprintf(file, "Rounds Won: %d\n", wins);
    fprintf(file, "Rounds Lost: %d\n", losses);
    fprintf(file, "Winning Hands:\n");
    fprintf(file, "  Straight Flush: %d\n", hand_wins[1]);
    fprintf(file, "  Four of a Kind: %d\n", hand_wins[2]);
    fprintf(file, "  Full House: %d\n", hand_wins[3]);
    fprintf(file, "  Flush: %d\n", hand_wins[4]);
    fprintf(file, "  Straight: %d\n", hand_wins[5]);
    fprintf(file, "  Three of a Kind: %d\n", hand_wins[6]);
    fprintf(file, "  Two Pairs: %d\n", hand_wins[7]);
    fprintf(file, "  Pairs: %d\n", hand_wins[8]);
    fclose(file);
    printf("Game statistics written to a separate file.\n");
}


int main(void) {
    int wins = 0, total_rounds = 0, rounds_won = 0, rounds_lost = 0;
    int hand_wins[9] = {0};
    char name[100];
    int hand[5];
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
    
    /*while(con != -1){ //stop game once con = -1; 
      
        if(plays > 25){ //once the deck deals over 25 cards and coins are greater than 0, then it will shuffle
            shuffle_deck(list);
            plays = 0; 
        }
        
       
        int c_count, coins_entered;
        int skip = 0; 
        
        printf("%s has %d coins.\n", name, coins);
        
        while(skip != 1){ //repeats until you put in a value number of coins
            printf("Please enter an amount of coins to start playing: ");
            scanf("%d", &coins_entered);
             
            if ((coins_entered > 0) && (coins_entered <= coins)) {
                skip = 1; 
        
            }
        }
        
        coins = coins - coins_entered; //you will have this number of coins left if you lose
        
       plays = deal_card(hand, plays, list); //deal_card will move the plays value by +5. 
       
       printf("You have been dealt 5 cards.\n\n");
            
       sort(hand, list); //sort hand 
       printf("%s's hand: ",name);
        
        printCard(list, hand); //prints hand.
    int swap = 0; */
    
    while (con != -1 && coins > 0) { //game ends when player loses all coins or con = -1.
        if (plays > 25) { shuffle_deck(list); plays = 0; }
        printf("%s has %d coins.\n", name, coins);
        int coins_entered, skip = 0;
        while (skip != 1) {//Program continues until -1 is typed.
            printf("Please enter an amount of coins to start playing: ");
            scanf("%d", &coins_entered);
            if (coins_entered > 0 && coins_entered <= coins) skip = 1;
        }
        coins -= coins_entered;
        plays = deal_card(hand, plays, list);
        printf("You have been dealt 5 cards.\n");
        sort(hand, list);
        printf("%s's hand: ", name);
        printCard(list, hand);
        
        int condition = play(list, hand);
        printf("Suggested cards to keep: %s %s\n", 
               suggest_cards_to_keep(list, hand, condition), 
               get_hand_type(condition));

        int swap = 0;
        while (swap != -1) { //Swaps the card of player's choosing (their input of 1-5)
            printf("Enter card 1-5 to change or -1 to stop: ");
            scanf("%d", &swap);
            if (swap > 0 && swap < 6) {
                hand[swap - 1] = plays;
                plays++;
                sort(hand, list);
                printf("%s's hand: ", name);
                printCard(list, hand);
                condition = play(list, hand);
                printf("Suggested cards to keep: %s. %s\n", 
                       suggest_cards_to_keep(list, hand, condition), 
                       get_hand_type(condition));
            }
        }

        sort(hand, list);
        printf("%s's final hand: ", name);
        printCard(list, hand);
        
        condition = play(list, hand);
        printf("%s\n", get_hand_type(condition));

        int payout = condition * coins_entered;
        if (condition == 0) {
            printf("You lose %d coins.\n", coins_entered);
            rounds_lost++;
        } 
        else {
            printf("You win %d coins.\n", payout);
            rounds_won++;
            hand_wins[condition]++;
        }
        coins += payout;

        printf("You have %d coins.\n", coins);
        if (coins <= 0) {
            printf("Game over.\n");
            break;
        }
        printf("Continue? Enter a number: (-1 to quit): ");
        scanf("%d", &con);
        total_rounds++;
    }

    write_statistics_to_file(total_rounds, rounds_won, rounds_lost, hand_wins); //Calls function to write data after game ends. 
    printf("Thanks for playing!\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct card_S {
    char suit;
    int rank;

 } card;
 
 void sort(int hand[], card list[]){ //Function will sort each card by numeric value
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
    printf("\n\n");
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
        else{         //otherwise it's just 3 in a row
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
    else{    //otherwise it's just a normal flush 
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

    int wins;
    wins = 0; 
    char name[100];
    int hand[5];
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
        
       
        int c_count, coins_entered;
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
       
       printf("You have been dealt 5 cards.\n\n");
            
       sort(hand, list); //sort hand 
       printf("%s's hand: ",name);
        
        printCard(list, hand); //prints hand.
    int swap = 0; 
    
    while(swap != -1){
        printf("Enter card 1-5 to change or -1 to stop:");
        scanf("%d", &swap);
            if(swap > 0 && swap < 6){
            hand[swap-1] = plays + 1; 
            plays = plays + 1;               //array starts a 0, so swap needs to be subtracted by one
            plays = hand[swap-1]; //swaps card with the top card on the deck. Swap moves up by one as you are going down the deck
        }
    }

    sort(hand, list);
    printf("%s's hand: ",name);
    printCard(list, hand); //shows new hand 
    
    wins = play(list, hand); //play function will find if you have any win conditions
                             //then it will assign how much it's worth. function doens't return win condition but rather it's money value.
                             
     c_count = wins * coins_entered; //mulitply wins with the amount of coins you entered
        if(wins == 0){
        printf("you lose %d coins \n", coins_entered);
        }
        
        if(wins != 0){
        printf("you win %d coins \n", c_count);
        }
        
    
    coins = coins + c_count; //new amount of coins
    printf("\nyou have %d coins\n", coins);
    
    if(coins <= 0){
        printf("Game over");
        break; //lose game when you have 0 coins
    }
    
    printf("Continue? (-1 to quit):\n\n");
    scanf("%d", &con); //if you still have coins, you can choose to keep playing

}
printf("Thanks for playing!");
    return 0;
}
