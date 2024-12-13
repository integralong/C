//
//  project2_practice_0.c
//  
//
//  Created by Lauren Song on 9/10/24.
//

// COP 3514
// Project #2 Task #1
// Lauren Song U79789182
// This program is to calculate the number of oscillating performances, which are grades that are higher or lower than all previous grades.
// The first grade is excluded from the oscillating performance count.

#include <stdio.h>

int main(){
    int number;
    
    printf("Enter the number of grades: ");
    scanf("%d", &number);
    
    
    int grades[number];
    printf("Enter the grades: ");
    
    for (int i = 0; i < number; i++){
        scanf("%d", &grades[i]);
        //Grades are values from 0 to 10000.
        if (grades[i] < 0 || grades[i] > 10000){
            printf("Invalid grades");
        }
    }
    
    int count = 0;
    int i;
    int j;
    int update_max = grades[0];
    int update_min = grades[0];

    //Check grades to count those that are either higher or lower than all previous grades
    for (i = 1; i < number; i++){
        int is_valid_higher = 1; //initialize to 1 (true) flags
        int is_valid_lower = 1; //initiatlize to 1 (true) flags
        // Compare with previous grades
        for (j = 0; j < i; j++){
            if (grades[i] <= grades [j]){
                is_valid_higher = 0;
            }
            if (grades[i] >= grades [j]){
                is_valid_lower = 0;
            }
        }
        //If either condition is true, count the grade
        if(is_valid_higher == 1 || is_valid_lower == 1){
            count++;
        }
        //Update maximum of grades
        if(grades[i] > update_max){
            update_max = grades[i];
        }
        //Update minimum of grades
        if(grades[i] < update_min){
            update_min = grades[i];
        }
       
    }
    printf("%d\n", count);
    return 0;
}
