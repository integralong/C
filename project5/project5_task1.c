//
//  project5_practe_3.c
//  
//
//
/*
 COP 3514
 Lauren Song U79789182
 project 5_task1
 
 This program splits a two-word string into two words, stores in word1 and word2.
 The words in the input string are separated by one or more white space(s). There might be additional white spaces before or after the word.
 */

/*
 - assume the input is no more than 1000 characthers
 - use read_line function (pointer version)
 - use void split(char *input, char *word1, char *word2);
 
 */

#include <stdio.h>
#define MAX_LEN 1000

void split(char *input, char *word1, char *word2) {
    //skip the spaces
    while (*input == ' ') {
        input++;
    }

    //copy the word1
    while (*input != '\0' && *input != ' ' && *input != '\n') {
        *word1++ = *input++;
    }
    *word1 = '\0'; // add a null terminator to the end of word1

    //skip the spaces between word1 and word2
    while (*input == ' ') {
        input++;
    }

    //copy the word2
    while (*input != '\0' && *input != ' ' && *input != '\n') {
        *word2++ = *input++;
    }
    *word2 = '\0'; //add a null terminator to the end of word2
}

//function to read a line of input from the user
void read_line(char *buffer, int max_len) {
    fgets(buffer, max_len, stdin);
    
    char *p = buffer;
    while (*p != '\0') {
            break;
        }
        p++;
}

int main() {
    char input[MAX_LEN]; //buffer to store user input
    char word1[MAX_LEN], word2[MAX_LEN]; //buffer to store word1 and word2

    printf("Enter input:");
    
    read_line(input, MAX_LEN); //call read_line to get user input and store it in input buffer
    split(input, word1, word2); //call split to separate input into word1 and word2

    printf("Word #1: %s\n", word1); //print word1
    printf("Word #2: %s\n", word2); //print word2
    
    return 0;
}
