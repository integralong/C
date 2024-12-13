//
//  project2_practice_4.c
//  
//
//  Created by Lauren Song on 9/16/24.
//
// COP3514
// Project #2 Task #2
// Lauren Song U79789182
// This program simulates a gaime similar to Scrabble. It reads two sequences of characters from the user and calculates points based on specific rules to determine the winner.
// Specifically, the rule of game is below:
// The sequences are composed of lowercase letters and whitespaces.
// One point per vowel a, e, i, o, u
// Two points per popular consonant t, n, s, r, h
// Three points for any other letter (white spaces are ignored to get points)



#include <stdio.h>

//Main function: set the game rules and determine who is a winner
int main()
{
    char ch;
    int count = 0;
    printf("Enter the first sequence: ");
    
    ch = getchar(); //Reads and calculate points for the first sequence
    
    while(ch != '\n')
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            count += 1;

        }else if(ch == 't' || ch == 'n' || ch == 's' || ch == 'r' || ch == 'h'){
            count += 2;

        }else if(ch != ' '){
            count += 3;

        }
        ch = getchar();
    }
    
    int count2 = 0;
    printf("Enter the second sequence: ");
    
    //Read and calculate points for the second sequence
    ch = getchar();
    while(ch != '\n')
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            count2 += 1;

        }else if(ch == 't' || ch == 'n' || ch == 's' || ch == 'r' || ch == 'h'){
            count2 += 2;

        }else if(ch != ' '){
            count2 += 3;

        }
        ch = getchar();
    }
    
    // Determine and print the result
    if(count > count2){
        printf("Marjorie wins!\n");
    }else if(count2 > count){
        printf("John wins!\n");
    }else if(count == count2){
        printf("Play again!\n");
    }
    return 0;
}
