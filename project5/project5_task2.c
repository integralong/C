//
//  project5_practice_2.c
//  
//
//
/*
 COP 3514
 Lauren Song U79789182
 project 5_task2
 
 This program is a two-player game that calculates points for each character, determines the
 winner, and prints the result.
 
 
 modify your program for project 2, task#2 with the following changes:
 - inputs are entered as command-line argument.
- the inputs are single words instead of a sequence of words
 - use function int calculate_score(char *word);
 
 */

#include <stdio.h>

int calculate_score(char *word) {
    int count = 0; //initialize score to zero
    char *ch = word; //pointer to the start of the word
    
    while(*ch != '\0') { //iterate until we reach the null terminator
        if (*ch == 'a' || *ch == 'e' || *ch == 'i' || *ch == 'o' || *ch == 'u') {
            count += 1;
        }else if (*ch == 't' || *ch == 'n' || *ch == 's' || *ch == 'r' || *ch == 'h') {
            count += 2;
        }else if (*ch != ' ') {
            count += 3;
        }
        ch++; //move to the next character
    }
    return count;
}


int main(int argc, char *argv[]) {
    if(argc != 3) { //if the number of arguments is not 3, invalid number of arguments
        printf("invalid number of arguments\n");
        return 1;
    }

    int count1, count2;
    
    //call calculate_score to alculate points
    count1 = calculate_score(argv[1]);
    count2 = calculate_score(argv[2]);

    //determine who is the winner and print the result
    if(count1 > count2) {
        printf("Marjorie wins!\n");
    }else if (count2 > count1) {
        printf("John wins!\n");
    }else {
        printf("Play again!\n");
    }

    return 0;
}
