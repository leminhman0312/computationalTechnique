#include<stdio.h>
#include<iostream>
using namespace std;
void addMatrix(float x[][11] , float y[][11], int nrow, int ncol);
void subtractMatrix(float x[][11], float y[][11], int nrow, int ncol);
void multiplyMatrix(float x[][11], float y[][11], int nrow, int ncol);
void transposeMatrix(float x[][11], float y[][11], int nrow, int ncol);





int main() {

	FILE *outfile;
	outfile = fopen("max_le_hmwk1_results.txt","a");
	
	int n_row,n_col, i, j;
	float first[11][11],second[11][11];
	
	cout << "Nrow, Ncol: ";
	scanf("%d%d", &n_row,&n_col);
	/* Entering 1st matrix */
	fprintf(outfile,"\n");
	fprintf(outfile,"-------INPUT----------\n");
	
	printf("Enter 1st matrix element: ");
	fprintf (outfile, "First matrix = \n");
	for (i=1;i<=n_row;i++){

		for(j=1;j<=n_col;j++){

			scanf("%f",&first[i][j]);
			fprintf(outfile,"%.2f",first[i][j]);
			fprintf(outfile," \t");				

		}
		printf(" \n");
		fprintf(outfile,"\n");
	}


	/* Entering 2nd matrix */
	printf("Enter 2nd matrix element: ");
	fprintf (outfile, "Second matrix = \n");
	for (i=1;i<=n_row;i++){

			for(j=1;j<=n_col;j++){

				scanf("%f",&second[i][j]);
				fprintf(outfile,"%.2f",second[i][j]);	
				fprintf(outfile," \t");			
			}
		printf(" \n");
		fprintf(outfile,"\n");
	}
	fprintf(outfile,"\n");
	
	
	addMatrix(first, second, n_row, n_col);
	subtractMatrix(first,second,n_row,n_col);
	multiplyMatrix(first,second,n_row,n_col);
	transposeMatrix(first,second,n_row,n_col);
	fclose(outfile);
	return 0;
}





/* Add function */ 

void addMatrix(float x[][11] , float y[][11], int nrow, int ncol) {
	FILE *outfile;
	outfile = fopen("max_le_hmwk1_results.txt","a");
	fprintf(outfile,"\n");
	fprintf(outfile, "RESULTS OUTPUT \n");
	fprintf(outfile,"------------------------ \n");
	fprintf(outfile,"Addition: \n"); 
	
	for (int i = 1; i<=nrow;i++){
		for (int j=1;j<=ncol;j++) {
			printf("%.2f",x[i][j]+y[i][j]);
			printf("\t");
			fprintf(outfile,"%.2f",x[i][j]+y[i][j]);
			fprintf(outfile," \t");
		}
		printf(" \n");
		fprintf(outfile,"\n");
	}
	fclose(outfile);
}

/* Subtract function */ 

void subtractMatrix(float x[][11], float y[][11], int nrow, int ncol){
	FILE *outfile;
	outfile = fopen("max_le_hmwk1_results.txt","a");
	fprintf(outfile,"Subtraction: \n"); 
	for (int i =1;i<=nrow;i++){
		for (int j=1;j<=ncol;j++){

			printf("%.2f", x[i][j]-y[i][j]);
			printf("\t");
			fprintf(outfile,"%.2f",x[i][j]-y[i][j]);
			fprintf(outfile," \t");

		}
		printf("  \n");
		fprintf(outfile,"\n");

	}
	fclose(outfile);
}

/*Multiply function */ 

void multiplyMatrix(float x[][11], float y[][11], int nrow, int ncol){
	FILE *outfile;
	outfile = fopen("max_le_hmwk1_results.txt","a");

	fprintf(outfile,"Multiplication: \n"); 
	for (int i=1;i<=nrow;i++){

		for (int j=1;j<=ncol;j++){
			float element = 0;
			for (int k =1;k<=nrow;k++){
				element = element + (x[i][k]*y[k][j]);

			}
			printf("%.2f",element);
			printf("\t");
			fprintf(outfile,"%.2f",element);
			fprintf(outfile," \t");
		}
		printf("  \n");
		fprintf(outfile,"\n");

	}
	fclose(outfile);

}

/* Transpose matrix */ 

/* Transpose 1st matrix */ 

void transposeMatrix(float x[][11], float y[][11], int nrow, int ncol){
	FILE *outfile;
	outfile = fopen("max_le_hmwk1_results.txt","a");

	fprintf(outfile,"Transpose of 1st: \n"); 
	
	for (int i=1;i<=nrow;i++){
		for (int j=1;j<=ncol;j++){

			printf("%.2f", x[j][i]);
			printf("\t");
			fprintf(outfile,"%.2f",x[j][i]);
			fprintf(outfile," \t");
		}
		printf("  \n");
		fprintf(outfile,"\n");
	}

	fprintf(outfile,"Transpose of 2nd: \n"); 
	
	for (int i =1; i<=nrow;i++){
		
		for(int j=1; j<=ncol; j++){
			
			printf("%.2f",y[j][i]);
			printf("\t");
			fprintf(outfile,"%.2f",y[j][i]);
			fprintf(outfile," \t");
		}
		printf("  \n");
		fprintf(outfile,"\n");
	}
	fclose(outfile);
}



