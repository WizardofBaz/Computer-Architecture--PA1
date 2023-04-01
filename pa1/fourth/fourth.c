#include <stdio.h>
#include <stdlib.h>

/*int** multiply(int** A, int first_rows,int first_cols ,int** B , int second_rows,int second_cols){
	int ** result = (int **) malloc(first_rows*sizeof(int*));
	int i, r, w,answer;
	for(i = 0; i < first_rows; i++){
		printf("%d", i);
		result[i] = calloc(second_cols, sizeof(int));
		for(r = 0; r <second_cols;r++){
			printf("%d", r);
			answer = 0;
			for(w =0; w < first_cols;w++){
				answer += A[i][w] * B[w][r];
			}
			printf("%d\t",answer);
		}
		printf("\n");
	} 
return result;

}
*/


int main(int argc, char** argv){

	if (argc < 2){
		printf("Bad input");
	}
		
	FILE *file1;
	file1 = fopen (argv[1],"r");

	if(file1 == NULL || file1 <= 0){
		printf("Empty File!");
		return 0;
	}
	int first_rows = 0;
	int first_cols = 0;
	int second_rows = 0;
	int second_cols = 0;

	
	fscanf(file1, "%d\t%d", &first_rows, &first_cols);
	//int[first_rows][first_cols] mat1;
	int mat1[first_rows][first_cols];
	int i = 0;
	while(i < first_rows) {
		int j = 0;
	//	printf("%d",first_cols);
		while(j < first_cols) {
			fscanf(file1, "%d\t", &mat1[i][j]);
	//		printf("%d", mat1);
			j++;
		}
		i++;
	}
	fscanf(file1, "%d\t%d", &second_rows, &second_cols); 
	//int [second_rows][second_cols] mat2;
	int mat2[second_rows][second_cols];

	if(first_cols != second_rows){
		printf("bad-matrices");
		return 0;
	}

	int s = 0;
	while (s < second_rows){
		int b = 0;
		while (b < second_cols) {
			fscanf(file1, "%d\t", &mat2[s][b]);
			b++;
		}
	s++;
}
//	int ** result = (int **) malloc(first_rows*sizeof(int*));
	int r, w,answer;
	for(i = 0; i < first_rows; i++){
		//printf("%d", i);
		//result[i] = calloc(second_cols, sizeof(int));
		//free(result[i]); //ADDED
		for(r = 0; r <second_cols;r++){
		//	printf("%d", r);
			answer = 0;
			for(w =0; w < first_cols;w++){
				answer += mat1[i][w] * mat2[w][r];
			
			}
			printf("%d\t",answer);
			
		}
		printf("\n");
//		free(result);
		//stops here
//	int c;
//	for (c = 0; c< first_rows;c++){
//		free(result[c]);
//}
//	free(result);
	}


//uncommenting = seg fault
/*
int c;
for(c = 0; c < first_rows; c++){
	free(result[c]);
}
free(results);

}
//free(mat2);
*/
fclose(file1);


}

//multiply(mat1,first_rows,first_cols,mat2,second_rows,second_cols);


	
