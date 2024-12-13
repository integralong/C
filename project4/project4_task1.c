//
//  project4_practice_3.c
//
//
//  Created by Lauren Song on 10/21/24.
//

/*
 COP 3514 F24
 Lauren Song U79789182
 This program is to determine who is the winner
 
 How to determine winner?
 -Two players pick largest number either first or the last number in the row
 -Players alternate who starts the round. Fist round is Marjorie first
 -Compare the highest sum for the picked numbers, then determine and print the winner
 */


#include <stdio.h>

void round_result(int *board, int n);

int main(void) {
    int T;
    scanf("%d", &T);
    
    //T should be in range [1, 100]
    if (T < 1 || T > 100) {
        printf("T must be between 1 and 100\n");
        return 1;
    }
    
    for (int round = 0; round < T; round++) {
        int N;
        scanf("%d", &N);
        
        //N should be in range [1, 1000]
        if (N < 1 || N > 1000) {
            printf("N must be between 1 and 1000\n");
            return 1;
        }
        
        int board[N];
        int *p = board;
        
        while(p < board + N){
            scanf("%d", p);
            p++;
        }
        
        //Call the round_result function
        round_result(board, N);
    }
    
    return 0;
}

void round_result(int *board, int n) {
    static int round = 0;  // Static variable to keep track of rounds
    int sum_of_marjorie = 0;
    int sum_of_john = 0;
    int *start = board;
    int *end = board + n - 1;


    int take_turn = (round % 2); //Even number round for Marjorie, Odd number round for John

    
    while (start <= end) {
        //Check which one is largest number to take (the first or last)
        int temp;
        if (*start > *end) {
            temp = *start;
            start++;
        } else {
            temp = *end;
            end--;
        }
        
        if (take_turn == 0) {
            sum_of_marjorie += temp;
        } else {
            sum_of_john += temp;
        }
        
        //Switch turns
        take_turn = 1 - take_turn;
    }
    
    //Print who is the winner
    if (sum_of_marjorie > sum_of_john) {
        printf("Marjorie\n");
    } else if (sum_of_marjorie < sum_of_john) {
        printf("John\n");
    } else {
        printf("Draw\n");
    }
    round++;
}
