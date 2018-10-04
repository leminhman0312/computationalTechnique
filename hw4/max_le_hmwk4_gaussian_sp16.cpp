#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main();
void gaussianElim(float a[][20], float b[], int n_row, int n_col);

int main(){
	FILE *outfile;
	outfile = fopen("max_le_hmwk4_sp16_gaussian_results.txt","a");
	fprintf(outfile, "\n");
	fprintf(outfile, "Gaussian Elimination to solve linear equations\n");
	fprintf(outfile, "-------------INPUT--------- \n");
	fprintf(outfile, "Starting wih Ax = B \n");
	fprintf(outfile,"\n");
	
	int n_row, n_col,i, j, imax, jmax;
	float first[20][20],second[20];
	
	cout << "Nrow, Ncol for A: ";
	scanf("%d%d", &n_row, &n_col);
	
	
	
	//Entering matrix A
	printf("Enter matrix A: ");
	fprintf(outfile, "A = \n");
	
	for (i = 0; i<n_row; i++){
		
		for (j = 0; j<n_col; j++){
			
			scanf("%f", &first[i][j]);
			fprintf(outfile, "%7.3f", first[i][j]);
			fprintf(outfile, " \t");

			printf("%7.3f", first[i][j]);
			printf(" \t");
		}
		printf(" \n");
		fprintf(outfile, "\n");

	}
	fprintf(outfile, "\n");
	fprintf(outfile, "\n");
	
	//Enter vector B
	
	printf("Enter vector B: ");
	fprintf(outfile, "B = \n");
	
	for (i = 0; i<n_row; i++){
		scanf("%f", &second[i]);
		fprintf(outfile, "%7.3f", second[i]);

		printf("%7.3f", second[i]);
		printf(" \n");
		fprintf(outfile, "\n");

	}
	fprintf(outfile, "\n");
	fprintf(outfile, "\n");

	
	fclose(outfile);
	
	gaussianElim(first, second, n_row, n_col);
	
	return 0;

}


//Starting Gaussian Elimination, solving a*x = b

void gaussianElim(float a[][20], float b[], int n_row, int n_col){

	FILE *outfile;
	outfile = fopen("max_le_hmwk4_sp16_gaussian_results.txt","a");
	fprintf(outfile, "-------------RESULTS OUTPUT---------\n");
	fprintf(outfile, "Final form to solve: Ux = g \n");
	
	float m[20][20];
	int maxiter = n_row - 1;
	int iter = 1;
	int ist, jst; 
	float x[20];
	float sum = 0.0;
	double temp;
	
	for(iter = 1; iter <= maxiter; iter++) {
		cout << "Iteration: " << iter << endl;
		ist = iter;
		jst = iter - 1;
		for (int j = jst; j<n_col; j++){
			for (int i = ist; i<n_row; i++) {
				m[i][j] = a[i][jst]/a[jst][jst];
			}
		}
		
		for (int j = jst; j< n_col; j++) {
			for(int i = ist; i< n_row; i++){
				a[i][j] = a[i][j]-(m[i][j]*a[jst][j]);
				if(j == jst) {
					b[i] = b[i] - m[i][j]*b[jst];
				}
			}
		}
		fprintf(outfile,"\n");
	
		
	
		

	}
	
	fprintf(outfile, "U =  \n");
	printf("U =  \n");
		for(int i = 0; i < n_row; i++) {
			for(int j = 0; j < n_col; j++) {
				fprintf(outfile, "%7.3f \t",a[i][j]);
				printf("%7.3f \t",a[i][j]);
			}
			fprintf(outfile,"\n");
			printf("\n");
		}
		
		fprintf(outfile, "g =  \n");
		for(int i = 0; i < n_row; i++) {
			fprintf(outfile,"%7.3f \n", b[i]);
		}
		fprintf(outfile,"\n");
	//Calculate X's 	


	x[n_row-1] = b[n_row-1] / a[n_row-1][n_row-1];
	for (int i = n_row-2; i >=0; i--){
		temp = b[i];
		for (int j = (i+1); j<n_row; j++){
			
			temp -= (a[i][j] * x[j]);
		}
		x[i] = temp / a[i][i];		
		
	}
	printf("Answers: \n");
	fprintf(outfile, "Answers: \n");
	for (int i = 0; i <n_row; i++){
		printf("x%d = %lf\n", i , x[i]);
		
		fprintf(outfile, "x%d = %7.3f\n", i , x[i]);
	}
	
	
	fclose(outfile);

}
































