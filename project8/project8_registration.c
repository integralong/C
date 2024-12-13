/*
COP 3514
Project 8: Registration
Lauren Song U79789182
This program generate a queue of students that intend to take COP3514 in the next semester
using a linked list.
User can several function by operation code. 
For example, user prompt to add students or check their gpa and cop3510 minimum grade,
or delete them.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define NAME_LEN 100
#define NETID_LEN 40

struct student {
	char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade;
	double gpa;
	int attempts;
	struct student *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

void help();
void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts);
struct student * add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts);
struct student * pop_student(struct student *registration);
void list_students(struct student *registration);
void list_gpa_min(struct student *registration, double gpa);
void list_cop2510_min(struct student *registration, int cop2510_grade);
struct student * clear_queue(struct student *registration);


///////////////////
// main function //
///////////////////

int main() {
	char code;
	char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade;
	double gpa;
	int attempts;

	struct student *registration = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'h':
				help();
				break;
			case 'a':
				read(name, netid, &cop2510_grade, &gpa, &attempts);
				registration = add_student(registration, name, netid, cop2510_grade, gpa, attempts);
				break;
			case 'p':
				registration = pop_student(registration);
				break;
			case 'l':
				list_students(registration);
				break;
			case 'g':
				read(NULL, NULL, NULL, &gpa, NULL);
				list_gpa_min(registration, gpa);
				break;
			case 'c':
				read(NULL, NULL, &cop2510_grade, NULL, NULL);
				list_cop2510_min(registration, cop2510_grade);
				break;
			case 'q':
				registration = clear_queue(registration);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}

//////////////////////////
// function definitions //
//////////////////////////

void help() {
	printf("List of operation codes:\n");
	printf("\t'h' for help;\n");
	printf("\t'a' for adding a student to the queue;\n");
	printf("\t'p' for removing a student from the queue;\n");
	printf("\t'l' for listing all students in the queue;\n");
	printf("\t'g' for searching students with a minimum GPA;\n");
	printf("\t'c' for searching students with a minimum grade in COP2510;\n");
	printf("\t'q' to quit.\n");
}

void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts) {
	if(name != NULL) {
		printf("Enter the name of the student: ");
		scanf("%[^\n]", name);
	}
	if(netid != NULL) {
		printf("Enter the NetID of the student: ");
		scanf("%s", netid);
	}
	if(cop2510_grade != NULL) {
		printf("Enter the COP2510 letter grade: ");
		scanf(" %c", cop2510_grade);
	}
	if(gpa != NULL) {
		printf("Enter the GPA: ");
		scanf("%lf", gpa);
	}
	if(attempts != NULL) {
		printf("Enter the number of previous attempts: ");
		scanf("%d", attempts);
	}
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////

/*
add_student: receives the registration linked list and the values for student name, NetID, COP2510 grade, GPA, and number of previous attempts, 
and adds the new student to the registration linked list; this function returns a pointer to the updated queue;
*/

struct student * add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts) {
	struct student *new_student;
	new_student = malloc(sizeof(struct student));
	if(new_student == NULL){
		printf("malloc faiiled in add_student\n");
		return registration;
	}
	//strings
	strcpy(new_student ->name, name);
	strcpy(new_student ->netid, netid);
	new_student -> cop2510_grade = cop2510_grade;
	//numbers
	new_student -> gpa = gpa;
	new_student ->  attempts = attempts;
	new_student -> next = NULL;

	//if the list is empty, new student first come, first serve
	if(registration == NULL){
		return new_student;
	}
	//if there at least one student
	struct student *old_student = registration;
	while(old_student -> next != NULL){
		old_student = old_student -> next;
	}

	//add the new student to the registration list
	old_student -> next = new_student;
	//return a pointer to the update queue;
	return registration;

	

}
/*
pop_student: receives the registration linked list, prints the information of the next student to be registered (first come, first serve basis), 
and removes it from the queue; if the queue is empty, this function does nothing; this function returns a pointer to the updated queue;
*/

struct student * pop_student(struct student *registration) {

	//if the queue is empty
	if(registration == NULL) return NULL;

	struct student *p = registration;
	
	// output format
	printf("|----------------------|----------------------|---------|-----|----------|\n");
	printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
	printf("|----------------------|----------------------|---------|-----|----------|\n");
	printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", p -> name, p -> netid, p -> cop2510_grade, p -> gpa, p -> attempts);
	printf("|----------------------|----------------------|---------|-----|----------|\n");

	registration = registration -> next;

	free(p);


	return registration;
}

/*
list_students: receives the registration linked list and lists all students in it; 
if the queue is empty, this function does nothing;
*/
void list_students(struct student *registration) {
	if(registration == NULL) return;

	struct student *p;
	{

	// output format
		printf("|----------------------|----------------------|---------|-----|----------|\n");
		printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
		printf("|----------------------|----------------------|---------|-----|----------|\n");
		for(p = registration; p != NULL; p = p -> next){
			printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", p -> name, p -> netid, p -> cop2510_grade, p -> gpa, p -> attempts);
			printf("|----------------------|----------------------|---------|-----|----------|\n");
		}
	}
	// ...
}
/*
list_gpa_min: receives the registration linked list and a minimum GPA value, 
lists all students in the list that satisfy this condition; 
if no students satisfy this condition, this function does nothing;*/
void list_gpa_min(struct student *registration, double gpa) {
    struct student *p = registration;
    int found = 0;

    for (p = registration; p != NULL; p = p->next) {
        if (p->gpa >= gpa) {
            if (!found) {
                printf("|----------------------|----------------------|---------|-----|----------|\n");
                printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
                printf("|----------------------|----------------------|---------|-----|----------|\n");
            }
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", p->name, p->netid, p->cop2510_grade, p->gpa, p->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
            found = 1;
        }
    }

    if (!found) {

    }
}

/*
list_cop2510_min: receives the registration linked list and a minimum COP2510 grade, 
lists all students in the list that satisfy this condition; 
if no students satisfy this condition, this function does nothing;*/
void list_cop2510_min(struct student *registration, int cop2510_grade) {

	struct student *p = registration;
	int found = 0;

	for(p = registration; p != NULL; p = p -> next){
		if(p -> cop2510_grade <= cop2510_grade){
			if(!found){
				printf("|----------------------|----------------------|---------|-----|----------|\n");
				printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
				printf("|----------------------|----------------------|---------|-----|----------|\n");
			}
			printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", p -> name, p -> netid, p -> cop2510_grade, p -> gpa, p -> attempts);
			printf("|----------------------|----------------------|---------|-----|----------|\n");
			found = 1;
		}
	}
	if(!found){

	}
}
/*
clear_queue: receives the registration linked list and deletes all students in it; 
this function returns a pointer to the updated queue.
*/
struct student * clear_queue(struct student *registration) {

	struct student *p;
	while(registration != NULL)
	{
		p = registration;
		registration = registration -> next;
		if(p != NULL)
			free(p);
	}
	return registration;
}
