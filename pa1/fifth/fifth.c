#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc,char *argv[]){
	
	char let;
	int w = 1;

	while(w <argc){
		char term[50];
		strcpy(term,argv[w]);
		w=w+1;
	

//	int a = 0;	
	int a;
	for (a = 0; a <strlen(term);a++){
		//don't need to worry about caps no more
		let = term[a];
		if(let == 'a' || let == 'e' || let == 'i' || let == 'o' || let == 'u' || let == 'A' || let == 'E' || let == 'I' ||let == 'O' || let == 'U'){
			printf ("%c",let);
		}
	}
//	printf("\n%s\n",term);

//doesn't work
//	if (let == 'a' || let == 'e' || let == 'i' || let == 'o' || let == 'u'){
//		printf ("%c",let);
}		
}
