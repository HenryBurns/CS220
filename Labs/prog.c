#include <stdio.h>
#include <stdlib.h>
struct student{
	char name[25];
	unsigned int age;
	char gender;
	unsigned long id;
	struct student* next;
};

void print_list(struct student* head){
	char gender;
	while(head){
		printf("Node at: %p\n", head);
		printf("Name: %s\n", head ->name);
		printf("Age: %u\n", head -> age);
		gender = head ->gender;
		if(gender == 'M')
			printf("Gender: Male");
		else if (gender == 'F')
			printf("Gender: Female");
		printf("\nID: %lu\n", head -> id);
		printf("Next node addr: %p\n", head->next);
		head = head-> next;
	}
}

int main(int x, char** y){
	FILE* fp;
	fp = fopen("input.txt", "r");
	char line[256];
	struct student* head_Student = (struct student*) (malloc(sizeof(struct student)));
	struct student* Last_Student = (struct student*) (malloc(sizeof(struct student)));
	if(fgets(line, 255, fp)){
		sscanf(line, "%[^:]:%d:%c:%lu ", &(head_Student-> name), &(head_Student ->age) , &(head_Student ->gender) , &(head_Student ->id));
		}
	while( fgets(line, 255, fp)){
		struct student* New_Student = (struct student*) (malloc(sizeof(struct student)));
		sscanf(line, "%[^:]:%d:%c:%lu ", &(New_Student-> name), &(New_Student ->age) , &(New_Student ->gender) , &(New_Student ->id));
		if(!head_Student -> next){
			head_Student -> next = New_Student;
			Last_Student = New_Student;
		}
		else{
			Last_Student -> next = New_Student;
			Last_Student = New_Student;
		}
	}
	print_list(head_Student);
}


