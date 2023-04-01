#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
int unique = 0;
struct Node {
	Node *next;
	Node *prev;
	int amount;
};

Node * head = NULL;

Node *Noder(int num){
	Node * new = (Node *) malloc(sizeof(Node));
	new -> amount = num;
	new -> next = NULL;
	new -> prev = NULL;
	return new;
}

void insert(Node * new){
	if(head == NULL){
		head = new;
		//unique++;
		//printf("number: %d # unique: %d \n", new -> amount, unique);
		return;
	}
	if(head -> next == NULL) {
		if(head -> amount < new -> amount) {
			head -> next = new;
			//unique++;
			//printf("number: %d # unique: %d \n", new -> amount, unique);
			return;
	 	} else if (head -> amount > new -> amount ){
			new -> next = head;
			head = new;
			//unique++;
			//printf("number: %d # unique: %d \n", new -> amount, unique);
			return;
		} else {
			new -> next = head;
			head = new;
			return;
		}
	} 
	if(head -> amount > new -> amount) {
		new -> next = head;
		head -> prev = new;
		head = new;
		//unique++;
		//printf("number: %d # unique: %d \n", new -> amount, unique);
		return;
	}
	Node * this = head -> next;
	Node * prev = head;
	while(this != NULL) {
		if( this -> amount >= new -> amount) {
			if(this -> amount != new -> amount ) {
				//unique++;
				//printf("number: %d # unique: %d \n", new -> amount, unique);
			}
			break;
		}
		prev = this;
		this = this -> next;
	}
	if(this == NULL) {
		//unique++;
	}
	new -> next = this;
	new -> prev = prev;
	if(prev != NULL) {
	prev -> next = new;  }
	if(this != NULL) {
		this -> prev = new;
	}
}
void freedom (Node *head){
	Node * intern;
	while (head != NULL){
		intern = head;
		head = head -> next;
		free(intern);
}

}

void delete(int number, int* n) {
	Node * ptr = head;
	//printf("deleting %d\n", number);
	if(ptr == NULL) {
		//printf("head is null returning now \n");
		//free(ptr); //ADDED
		return;
	}
	if(ptr -> next == NULL) {
		if(ptr -> amount == number) {
			head = NULL;
			*n = *n-1;
			free(ptr);
			return;
		}
	}
	Node * prev = NULL;
	while(ptr != NULL) {
		if(ptr-> amount == number) {
			*n=*n-1;
			break;
			//free(ptr); //ADDED
		}	
		prev = ptr;
		ptr = ptr -> next;
		//free(ptr); //ADDED
	}
	if(ptr == NULL){
		//free(ptr); //ADDED
		return;
	}

	if(ptr -> next != NULL && ptr -> prev != NULL) {
		Node * temp = ptr -> prev;
		if(prev != NULL) {
			prev -> next = ptr -> next;
			//free(ptr); //ADDED
		}
		if(ptr -> next != NULL) {
			ptr -> next -> prev = temp;
		}
		//*n=*n-1;
		free(ptr);
		return; 
	} 
	if(ptr -> next != NULL) {
		ptr -> next -> prev = NULL;
		head = ptr -> next;
		//free(ptr); //ADDED
	} 

	if(prev != NULL) {
		prev -> next = NULL;
		//free(ptr); //ADDED
	}
	//*n=*n-1;
	free(ptr);
}
/*
void stole (Node *first, Node *second){
	int run = first->amount;
	first->amount = second->amount;
	second->amount = run;
}


void bubble(Node *head){
	int changer;
	int bs;
	Node *ptr;
	Node *super = NULL;

	if(head == NULL){
		return;
	}
	do {
		int flipper = 0;
		ptr = head;
	while(ptr ->next != super){
		if(ptr -> amount > ptr -> next ->amount){
		stole(ptr, ptr->next);
		flipper = 1;	
	}
	ptr = ptr ->next;
	}
	super = ptr;
}
while (stole);
} */

int main(int argc, char *argv[]){
	if(argc !=2 ) {
		printf("error\n");
		return -1;
	}

	FILE *file2;
	file2 = fopen(argv[1],"r");
	
	if(file2 == NULL){
		printf("error\n");
		return 0;
	}
int number;
char option;
int inserts = 0;
int* n = &inserts;
while(fscanf(file2, "%c\t%d\n", &option, &number) != EOF) {
	Node *new = Noder(number);
	if(option == 'i') {
		//printf("adding %d\n\n", number);
		insert(new);
		inserts++;
	} else {
		delete(number, n);
		free(new); //ADDED 
	}
	//printf("head is currently %d\n", head-> amount);
}
printf("%d\n", inserts);

Node * printPtr = head;
int previousNumber = -1123131312;
while(printPtr != NULL) {
	if(previousNumber != printPtr -> amount) {
		printf("%d", printPtr->amount);
		if(printPtr -> next != NULL) {
			printf("\t");
		}
	}
	previousNumber = printPtr -> amount;
	printPtr = printPtr ->next;
}
printf("\n");

freedom(head);
fclose(file2);
}








	




