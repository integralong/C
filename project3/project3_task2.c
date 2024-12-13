//
//  Project3_practice_6.c
//  
//
//  Created by Lauren Song on 9/23/24.
//
// COP 3514
// Project #3 Task #2
// Lauren Song U79789182
// This program is to find distinct numbers if a sequence that contains duplicates
// Then sorts them in ascending order
// The format is following functions:
// - int find_distinct(int numbers[], int result[]):
// for this function, it finds the distinct numbers from the array numbers and stores them in the array result
// - selection_sort function to sort the numbers after the distinct numbers are found


#include <stdio.h>

// Function to find distinct numbers
int find_distinct(int numbers[], int n, int result[]){
    int i, j;
    int distinct_num;
    int found_distinct = 0; //it keeps track of how many distinct numbers have been found
    
    for(i = 0; i < n; i++){
        distinct_num = 1; // Flag to check distinct number
        
        // Check if the number is already in the result array
        for(j = 0; j < found_distinct; j++){
            if(numbers[i] == result[j]){
                distinct_num = 0; // Not distinct
                break;
            }
        }
        if(distinct_num){ // If distinct, add to result array
            result[found_distinct] = numbers[i];
            found_distinct++;
        }
    }
    return found_distinct; // Return count of distinct numbers
}

// Function to sort the array using selection sort
void selection_sort(int numbers[], int n){
    int temp;
    int i, j;
    
    // Selection sort algorithm
    for(i = 0; i < n-1; i++){
        for(j = i + 1; j < n; j++){
            if(numbers[i] > numbers[j]){
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int main(void){
    int n, i;

    printf("Enter the size of sequence: ");
    scanf("%d", &n);
    
    int numbers[n];    // before finding distinct numbers array
    int result[n];     // after finding distinct numbers array, and stored distinct numbers
    
    printf("Enter numbers: ");
    for(i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }
    
    // Find distinct numbers
    int distinct_count = find_distinct(numbers, n, result);
    
    // Call the selection sort function to sort the distinct numbers
    selection_sort(result, distinct_count);
    
    // Print the sorted distinct numbers
    printf("Output: ");
    for(i = 0; i < distinct_count; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}
