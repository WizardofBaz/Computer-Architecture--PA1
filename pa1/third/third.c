#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
	struct Node {
	Node *next;
	Node *prev;
	int total;
}; 

int hkey (int key){
	if((key % 10000) < 0){
		return (key % 10000) + 10000;
	}
	if((key % 10000) > 0){
		return (key % 10000);
	}
	return 0;
}

void accidents (Node * htable[], int key){
	Node * this = htable[hkey(key)];
	Node * new = malloc(sizeof(Node));
	new -> next = NULL;
	new -> prev = NULL;
	new -> total = key;
while (this){
	if(this ->next == NULL){
		this -> next = new;
		new -> prev = this;
		break;
	}
	if (this ->next != NULL){
		this = this -> next;

		}
	}
}

Node * search(Node * htable[],int key){
Node * this = htable[hkey(key)];

	while(this){
		if(this ->total == key){
		return this;
	}
		this = this -> next;
	}


return NULL;
}

void freedom (Node *head){
Node * brand;
while(head !=NULL){
	brand = head;
	head = head -> next;
	free (brand);
}
}

int main(int argc, char* argv[]){
FILE *file;
file = fopen(argv[1],"r");

if(file == NULL){
	printf("error\n");
	return 0;
}
char alt;
int key;
int crashes;
int hunt;

Node * htable[10000];
int i = 0;
while (i < 10000){
	htable[i] = NULL;
	i++;
}
while(fscanf(file, "%c\t%d\n", &alt, &key) ==2){
	if(alt == 'i'){
		int dhash = hkey(key);

		if(htable[dhash] == NULL){
			Node * new = malloc(sizeof(Node));
			new -> total = key;
			new -> next = NULL;
			new -> prev = NULL;

			htable[dhash] = new;
			
		}
		else {
			accidents(htable,key);
			crashes++;	
			
		}
	}
 	else {
		if(search(htable,key)){
			hunt++;
		
		}
	}
		
}

printf("%d\n",crashes);
printf("%d\n",hunt);

int p;
for (p=0; p < 10000; p++){
	freedom(htable[p]);
}
fclose(file);
//fixes the mem leak!!!
}

