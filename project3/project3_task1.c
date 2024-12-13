//
//  Project3_practice_5.c
//  
//
//  Created by Lauren Song on 9/23/24.
//
// COP 3514
// Project #3 Task #1
// Lauren Song U79789182
// This program is to determine if a sequence is a good sequence
// If it is a good sequence, the program displays "yes" otherwise, it displays "no"

// What is the rule to be a good sequence?:
// - n is the size of sequence
// - each integer ai in the sequence is 0 <= ai < n
// - or ai is a square of some integer less than n


#include <stdio.h>

int main() {
    int i;
    int n;

    printf("Enter the size of sequence: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter numbers: ");
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Check if it follows the rule
    int follow_rule = 1; // Flag to indicate if all numbers follow the rule

    for (i = 0; i < n; i++) {
        // Check if the number is within the valid range
        if (0 <= a[i] && a[i] < n) {
            continue; // Valid range, continue to the next number
        } else {
            int num_square = 0; // Flag to indicate if the number is a square of some integers

            // Check if the number is a square by iterating over possible square roots
            for (int j = 0; j < n; j++) {
                if (j * j == a[i]) {
                    num_square = 1; // The number is a square
                    break;
                }
            }
            
            if (!num_square) {
                follow_rule = 0; // If it's neither in range nor a perfect square
                break;
            }
        }
    }

    if (follow_rule) {
        printf("Output: yes\n");
    } else {
        printf("Output: no\n");
    }
    
    return 0;
}
