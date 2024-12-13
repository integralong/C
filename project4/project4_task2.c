//
//  project4_practice_4.c
//  
//
//  Created by Lauren Song on 10/21/24.
//
/*
 COP 3514
 Lauren Song U79789182
 This program finds how many duplicates are present before and after each position in the array.
 It prints the result for the counts of duplicates before and after each position, respectively.
 */


#include <stdio.h>

void before_after(int *array, int n) {
    int *current_position = array;
    for (; current_position < array + n; current_position++) {
        int before = 0;
        int after = 0;
        
        //Count duplicates before the current position
        int *check_duplicate = array;
        for (; check_duplicate < current_position; check_duplicate++) {
            if (*check_duplicate == *current_position) {
                before++;
            }
        }

        //Count duplicates after the current position
        check_duplicate = current_position + 1;
        for (; check_duplicate < array + n; check_duplicate++) {
            if (*check_duplicate == *current_position) {
                after++;
            }
        }

        //print the result before and after
        printf("%d %d\n", before, after);
    }
}

int main() {
    //size of the array
    int n;
    scanf("%d", &n);
    
    if(n < 1 || n > 1000){
        printf("The size must be between 1 and 1000\n");
        return 1;
    }
    
    int array[n];

    //elements of the array
    int *p = array;
    
    for (; p < array + n; p++) {
        scanf("%d", p);
        if(*p < 1 || *p > 1000000){
            printf("The elements must be between 1 and 1000000\n");
            return 1;
        }
    }

    //Call the function
    before_after(array, n);

    return 0;
}
