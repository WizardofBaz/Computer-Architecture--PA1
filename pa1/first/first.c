#include <stdio.h>
#include <stdlib.h>

//step1 : load the file in 
//step2 : split even and odd numbers
//step 3 : put even into acending order
//step 4 : put odd into decending order

void printer1 (int l,int w, int bigE,int count[],int evens[],int bigO,int odds[],int hold){
	if(bigE != 0){
		for (l = 0; l < bigE; l++){
			count[l] = evens[l];
}
	}
	if(bigO != 0){
		for (w=0; w<bigO;w++){
		count [l] = odds [w];
		l++;
	}
}
l = 0;
do {
	printf("%d\t" , count[l]);
	l++;
} while ( l < hold - 1);
	printf("%d\n", count[l]);
	 

}

int main(int argc,char *argv[]){
	int temp, bigE, bigO, p;
	int evens [20];
	int odds [20];
	int count [20];
	//set it all to 20, i dont wanna malloc
	char *pave = argv[1];
	FILE *file1;
//	file1 = fopen(argv[1],"r");
	file1 = fopen(pave, "r");
	if(file1 == NULL){
		printf("error");
	return 0;
	}
	int hold;
//	int x;	

	fscanf(file1,"%d\n",&hold);
	if(hold == 0){
		return 0;
}

for (p = 0; p<hold; p++){
	fscanf(file1, "%d", &temp);
	if(temp%2 == 0){
		evens[bigE] = temp;
		bigE++;
}
	if(temp%2 != 0){
		odds[bigO] = temp;
		bigO++;
}	
	

}

int card,wow, intern;
if (bigO>0){
	for(card = 0; card < bigO-1; card++){
	for(wow = 0; wow < bigO-1;wow++){
		if(odds[wow] < odds[wow+1]){
			intern = odds[wow];
			odds[wow] = odds[wow + 1];
			odds [wow +1] = intern;
}
	}
		}
			}
	if(bigE > 0){

	for (card = 0; card < bigE -1; card++){
		for (wow = 0; wow < bigE -1; wow++){
			if(evens[wow] > evens[wow+1]) {
				intern = evens[wow];
				evens[wow] = evens[wow+1];
				evens[wow+1] = intern;
			}
		}
	}

}

int l = 0;
int w = 0;

printer1 (l,w,bigE,count,evens,bigO,odds,hold);
fclose (file1);

return 0;


//end bracket
}













	








			
		
