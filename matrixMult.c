// Rawan Alsaadi 10081442 
// Omar Toutounji 10169506
// Beltan Michel 10169162
#include<stdio.h>
#include<stdlib.h>
void printMatrix(int length, int width, int * Array){
	int i,j;
	for (i = 0; i <  length; i++){
		for (j = 0; j < width; j++)
			printf("%d\t", *(Array + i*width + j));
		printf("\n");
	}
}

void readMatrixElements(int length, int width, int *Array){
	int i,j;
	for (i = 0; i <  length; i++)
      for (j = 0; j < width; j++)         
		 if(scanf("%d",(Array + i*width + j)) != 1){
			//Invalid Input and exit gracefully with error code -1.
			fprintf(stderr, "Invalid Input");
			exit(-1);
		}

}
void matrixMul(int length1, int width1, int * array1, int length2, int width2, int * array2, int * multiply){
	int i,j,k,sum=0,n1,n2; 
	// Matrix Multiplication
	printf("\n\nMultiplication Result:\n");
	for (i = 0; i < length1; i++) {
      for (j = 0; j < width2; j++) {
		printf("\nElement [%d,%d] = ",i,j);
        for (k = 0; k < length2; k++) {
			n1 = *(array1 + i*width1 + k);
			n2 = *(array2 + k*width2 + j);
			if(k<length2 - 1) 
				printf("%d * %d + ",n1,n2);
			else
				printf("%d * %d ",n1,n2);

			sum = sum + n1*n2;
        }
 		printf("= %d ", sum);
        *(multiply + i*width2 + j) = sum;
        sum = 0;
      }
    }
}
int main(void)
{
	int length1, width1, length2, width2, length3, width3;
	int *array1;
	int *array2;
	int *multiply;
	int *multiply2;
	int *array3;
	
	printf("Insert matrix 1 dimensions separated by a space: ");	
	if(scanf("%d%d", &length1, &width1) != 2){
		//Invalid Input and exit gracefully with error code -1.
		fprintf(stderr, "Invalid Input");
		exit(-1);
	}

	

	printf("Insert matrix 2 dimensions separated by a space: ");	
	if(scanf("%d%d", &length2, &width2) != 2){
		//Invalid Input and exit gracefully with error code -1.
		fprintf(stderr, "Invalid Input");
		exit(-1);
	}


	while(width1 != length2){
		//Please re-input the second matrix dimensions
		fprintf(stderr, "****** Dimensions Mismatch. second matrix length must equal first matrix length*****\n");
				
		printf("Insert matrix 2 dimensions separated by a space: ");					
		if(scanf("%d%d", &length2, &width2) != 2){
			//Invalid Input and exit gracefully with error code -1.
			fprintf(stderr, "Invalid Input");
			exit(-1);
		}

	}
	
	array1 = (int *)malloc(length1 * width1 * sizeof(int));
	array2 = (int *)malloc(length2 * width2 * sizeof(int));
	multiply = (int *)malloc(length1 * width2 * sizeof(int));


	printf("Input matrix 1 elements separated by spaces: ");
	readMatrixElements(length1, width1, array1);

	printf("Input matrix 2 elements separated by spaces: ");
	readMatrixElements(length2, width2, array2);

	// print matrix1 elements
	printf("\n\nMatrix1:\n");
	printMatrix(length1,width1,array1);

	// print matrix2 elements
	printf("\n\nMatrix2:\n");
	printMatrix(length2,width2,array2);

	matrixMul(length1, width1, array1, length2, width2, array2, multiply);

	// print Final output elements
	printf("\n\nFinal output:\n");
	printMatrix(length1,width2,multiply);
	
	// bonus question
	printf("Insert new matrix 3 dimensions separated by a space: ");	
	if(scanf("%d%d", &length3, &width3) != 2){
		//Invalid Input and exit gracefully with error code -1.
		fprintf(stderr, "Invalid Input");
		exit(-1);
	}


	while(width2 != length3){
		//Please re-input the second matrix dimensions
		fprintf(stderr, "****** Dimensions Mismatch. third matrix length must equal multiply matrix length*****\n");
				
		printf("Insert matrix 3 dimensions separated by a space: ");					
		if(scanf("%d%d", &length3, &width3) != 2){
			//Invalid Input and exit gracefully with error code -1.
			fprintf(stderr, "Invalid Input");
			exit(-1);
		}

	}
	
	array3 = (int *)malloc(length3 * width3 * sizeof(int));
	multiply2 = (int *)malloc(length1 * width3 * sizeof(int));

	printf("\nInput matrix 3 elements separated by spaces: ");
	readMatrixElements(length3, width3, array3);
	// print matrix3 elements
	printf("\n\nMatrix3:\n");
	printMatrix(length3,width3,array3);

	matrixMul(length1, width2, multiply, length3, width3, array3, multiply2);

	// print Final output elements
	printf("\n\nFinal output:\n");
	printMatrix(length1,width3,multiply2);




	free(array1);
	free(array2);
	free(multiply);
	free(multiply2);
	free(array3);	
	return 0;
}