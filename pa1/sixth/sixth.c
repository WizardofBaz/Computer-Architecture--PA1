#include <stdlib.h>
#include <stdio.h>

int firstPrint = 0;
typedef struct Node Node;

struct Node {
	Node * right;
	Node * left;
	int amount;
};

void insert(Node * node, int amount){
	if (node == NULL){
		node = (Node *) malloc(sizeof(Node));
		node-> amount = amount;
	//	printf("%d added\n", amount);
	} else if (node -> amount == -123789456) {
		node -> amount = amount;
		node -> right = (Node*) malloc (sizeof(Node));
		node -> right -> amount = -123789456;
		node -> left = (Node*) malloc(sizeof(Node));
		node -> left -> amount = -123789456;
	 }
	else if ((node)-> amount > amount){
		insert(node -> left , amount);
	//	printf("%d: moving left\n", amount);
	}
	else if(node -> amount < amount){ 
		insert(node -> right, amount);
	//	printf("%d moving right\n", amount);
} 
}

void inOrder(Node *root){
	if (root == NULL){
	//	printf("Empty Tree");
		return;
	}
	if(root -> amount == -123789456) {return;}
	if (root != NULL){
		inOrder(root -> left);
		printf("%d\t", root ->amount);
		inOrder(root -> right);
	}
}
//prints tree
void tree (Node * root){
	if(root == NULL){
		return;
	}
	if(root -> amount == -123789456) {return;}
	tree(root -> left);
	if(firstPrint < 1) {
		printf("\t%d",root->amount);
	} else {
		printf("\t%d", root -> amount);
	}
	firstPrint++;
	tree(root -> right);

}
void freedom (Node * root){
	if(root == NULL){
		return;
	}
	freedom(root -> left);
	freedom(root -> right);
	free(root);
	
}

int main (int argc, char *argv[]){
FILE *file;
file = fopen(argv[1],"r");

if(file == NULL){
	printf("error");
}
Node *root = (Node *)malloc(sizeof(Node));
root -> amount = -123789456;
int number;
	while (fscanf(file,"i\t%d\n", &number) != EOF){
		insert(root,number);
	//	printf("%d\n", number);
	} 
	
//	printf("printing tree");
	inOrder(root);
//	tree(root);
	printf("\n");	
	
	freedom(root);	
	fclose(file);

//printf("-1000	-500	-250	-125	250	500	1000");		
}






