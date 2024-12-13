/*
COP 3514
Project 9
Task #2
Lauren Song U79789182
This program red in data from a file "customers.csv",
find out who have taken more than a certain number of lessons,
and write the result to the output file "result.csv".
-modified in order to use quick sort the customers by number of lessons.
-used the quick sort library function and implement the comparison function.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 200
#define MAX_LEN 100

struct customer {
    char email_address[MAX_LEN+1];
    int num_lessons;
    char name[MAX_LEN+1];
};

//function prototype for search
int search(struct customer list[], int n, int num_lessons, struct customer result[]);
int compare_lessons(const void *p, const void *q);

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
    while(fscanf(fp, "%[^,],%d,%[^\n]\n",
                list[n].email_address,
                &list[n].num_lessons,
                list[n].name) == 3) {
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
        fprintf(output_fp, "%s, %d,%s\n", result[i].email_address, result[i].num_lessons, result[i].name);
    }
    fclose(output_fp);
    printf("Output file name: result.csv\n");

    return 0;
}


//qsort comparison function
int compare_lessons(const void *p, const void *q) {
    const struct customer *p1 = (const struct customer *)p;
    const struct customer *q1 = (const struct customer *)q;

    return q1->num_lessons - p1->num_lessons;
}

//search in the array list for customers whose number of lessons are greater than num_lessons
//and store the result in the array result
//used qsort
int search(struct customer list[], int n, int num_lessons, struct customer result[]) {
    //sort the list by num_lessons
    qsort(list, n, sizeof(struct customer), compare_lessons);
    
    int i, count = 0;

    //store customers in sorted result array if num_lessons is greater
    for (i = 0; i < n; i++) {
        if (list[i].num_lessons > num_lessons) {
            result[count++] = list[i];
        }
    }
    return count;
}

