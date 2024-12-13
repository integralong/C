/*
COP 3514
Project 7
Lauren Song U79789182
This program red in data from a file "customers.csv",
find out who have taken more than a certain number of lessons,
and write the result to the output file "result.csv".
*/

#include <stdio.h>
#include <string.h>

#define MAX_CUSTOMERS 200
#define MAX_LEN 100

struct customer {
    char email_address[MAX_LEN+1];
    int num_lessons;
    char name[MAX_LEN+1];
};

//function prototype for search
int search(struct customer list[], int n, int num_lessons, struct customer result[]);

int main() {
    struct customer list[MAX_CUSTOMERS];
    int n = 0;
    FILE* fp;
    
    //open the file for reading
    if((fp = fopen("customers.csv", "r")) == NULL) {
        printf("File open error...\n");
        return 1;
    }

    //read each line using fscanf
    while(fscanf(fp, "%[^,],%d,%[^\n]", list[n].email_address, &list[n].num_lessons, list[n].name) == 3) {
        n++;
        if(n >= MAX_CUSTOMERS)
            break;
    }
    fclose(fp);
    
    int num_lessons;
    //prompt user enters the number of lessons for searching
    printf("Enter number of lessons: ");
    scanf("%d", &num_lessons);
    
    struct customer result[MAX_CUSTOMERS];
    int find_customers = search(list, n, num_lessons, result);

    //write the results to the output file
    FILE* output_fp;
    if((output_fp = fopen("result.csv", "w")) == NULL) {
        printf("File creation error...\n");
        return 0;
    }

    for(int i = 0; i < find_customers; i++) {
        fprintf(output_fp, "%s, %d,%s", result[i].email_address, result[i].num_lessons, result[i].name);
    }
    fclose(output_fp);
    printf("Output file name: result.csv\n");

    return 0;
}

//search in the array list for customers whose number of lessons are greater than num_lessons
//and store the result in the array result
int search(struct customer list[], int n, int num_lessons, struct customer result[]) {
    int i, count = 0;

    //find and store customers in result array if num_lessons is greater
    for (i = 0; i < n; i++) {
        if (list[i].num_lessons > num_lessons) {
            result[count++] = list[i];
        }
    }
    return count;
}


