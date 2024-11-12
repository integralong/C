/*
 COP 3514
 Project 6: Tokenizer
 Lauren Song U79789182
 This program tokenizes the text into words and collects unique words.
 Then it sorts the collected unique words alphabetically into an array.
 Finally, it prints the number of unique words, lists the unique words, and displays the index of
 each word based on its position in the original sentence.
 A sentence is considered to end with a period ".".
 */




#include <stdio.h>
#include <string.h>


#define MAX_LEN 100000

//function to sort unique words alphabetically and print them
void sort_and_print(FILE *fileout, const char *text) {
    char *words[10000];
    int word_count = 0;
    char text_copy[MAX_LEN];
    strcpy(text_copy, text);

    //tokenize the text into words and collect unique words in the array
    char *token = strtok(text_copy, " .\n");
    while (token != NULL) {
        int unique_word = 1;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i], token) == 0) {
                unique_word = 0;
                break;
            }
        }
        if (unique_word) {
            words[word_count++] = token; //add unique words to the array
        }
        token = strtok(NULL, " .\n");
    }

    //sort the unique words alphabetically
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    //print total count and alphabetically sorted unique words
    fprintf(fileout, "%d\n", word_count);
    for (int i = 0; i < word_count; i++) {
        fprintf(fileout, "%s\n", words[i]);
    }

    //print the index of sorted array based on its position in the original sentence
    char *sentence_start = (char *)text;
    while (*sentence_start != '\0') {
        char sentence[MAX_LEN];
        int sentence_length = 0;

        //sentence is considered to end with a period "."
        while (*sentence_start != '.' && *sentence_start != '\0') {
            sentence[sentence_length++] = *sentence_start++;
        }
        sentence[sentence_length] = '\0'; //null-terminate the sentence

        if (*sentence_start == '.') {
            sentence_start++; //skip the period
        }

        //tokenize sentence into words and print their index
        char *word = strtok(sentence, " .\n");
        while (word != NULL) {
            for (int i = 0; i < word_count; i++) {
                if (strcmp(words[i], word) == 0) {
                    fprintf(fileout, "%d ", i + 1); //print index of the word
                    break;
                }
            }
            word = strtok(NULL, " .\n");
        }
        fprintf(fileout, "\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    
    char input_filename[MAX_LEN], output_filename[MAX_LEN];
    strcpy(input_filename, argv[1]);
    strcat(input_filename, ".txt");
    
    strcpy(output_filename, argv[2]);
    strcat(output_filename, ".txt");
        

    FILE *filein = fopen(input_filename, "r");
    if (filein == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *fileout = fopen(output_filename, "w");
    if (fileout == NULL) {
        perror("Error opening output file");
        fclose(filein);
        return 1;
    }

    char text[MAX_LEN] = "";
    char line[MAX_LEN];

    //read the entire file into the text buffer
    while (fgets(line, sizeof(line), filein) != NULL) {
        strcat(text, line);
    }

    //call the sort_and_print function
    sort_and_print(fileout, text);

    fclose(filein);
    fclose(fileout);

    return 0;
}

