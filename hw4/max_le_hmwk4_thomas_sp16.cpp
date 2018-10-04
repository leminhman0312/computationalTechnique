#include<cmath>
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
void thomas(double* a, double* b, double* c, double* d, double* x, int n);

//THOMAS ALGORITHM: 

int main(){
	FILE *outfile;
	outfile = fopen("max_le_hmwk4_sp16_thomas_results.txt","a");
	
	int n; 
	double a[10],b[10],c[10],d[10];
	double x[10];
	
	cout << "Enter number of equations: \n";
	scanf("%d",&n);
	fprintf(outfile,"\n");
	fprintf(outfile,"Thomas Algorithm to solve tridiagonal matrix");
	fprintf(outfile, "\n");
	fprintf(outfile,"--------------GIVEN-------------\n");
	fprintf(outfile,"n = number of equations\n");
	fprintf(outfile,"D = main diagonal vector\n");
	fprintf(outfile,"B = below the main diagonal vector\n");
	fprintf(outfile,"A = above the main diagonal vector\n");
	fprintf(outfile,"C = right column vector\n");
	fprintf(outfile,"\n");
	
	
	fprintf(outfile,"--------------INPUT-------------\n");
	//Entering vectors 
	//Main diagonal vector
	printf("Enter the main diagonal vector D: ");
	fprintf(outfile, "D = \n");
	for (int i = 0; i < n; i++){
	
		scanf("%lf",&d[i]);
		fprintf(outfile,"%6.3lf", d[i]);
		fprintf(outfile, "\t");
		
	}
	fprintf(outfile, "\n");
	
	//Side vectors
	//Below diagonal
	
	printf("Enter B, below the main diagonal vector: ");
	fprintf(outfile, "B = \n");
	for (int i = 0; i < n; i++){
		scanf("%lf",&b[i]);
		fprintf(outfile,"%6.3lf", b[i]);
		fprintf(outfile,"\t");
	
	}
	fprintf(outfile, "\n");
	
	//Above diagonal 
	
	printf("Enter A, above the main diagonal vector: ");
	fprintf(outfile, "A= \n");
	for (int i = 0; i < n; i++){
		scanf("%lf",&a[i]);
		fprintf(outfile,"%6.3lf", a[i]);
		fprintf(outfile,"\t");
	
	}
	fprintf(outfile, "\n");
	
	//Right hand vector
	
	printf("Enter the right hand column vector C: ");
	fprintf(outfile, "C = \n");
	for (int i = 0; i < n; i++){
	
		scanf("%lf",&c[i]);
		fprintf(outfile,"%6.3lf", c[i]);
		fprintf(outfile,"\t");
	
	}
	printf("\n");
	fclose(outfile);
	thomas(a,b,c,d,x,n);
	fprintf(outfile, "\n");
	return 0;

}


void thomas(double* a, double* b, double* c, double* d, double* x, int n){
	
	FILE* outfile;
	outfile = fopen("max_le_hmwk4_sp16_thomas_results.txt","a");
	fprintf(outfile,"\n");
	fprintf(outfile,"------------OUTPUT-------------\n");
	fprintf(outfile, "\n");
	double m;
	int k;
	//Forward substitution
	
	for (k = 1; k< n; k++){
		m = b[k]/ d[k-1];
		d[k] = d[k] - m*a[k-1];
		c[k] = c[k] - m*c[k-1];
	}
	
	//Backward substitution
	
	x[n-1] = c[n-1]/d[n-1];
	
	for (k = n-2; k>=0; k--){
		x[k] = (d[k] - a[k]*x[k+1])/d[k]; 
	}
	printf("\n");
	printf("Solution vector X = \n");
	fprintf(outfile, "\n");
	fprintf(outfile,"Solution vector X = \n");
	
	for (k = 0; k< n; k++){
		printf("%6.3lf",x[k]);
		printf("\n");
		fprintf(outfile, "%6.3lf",x[k]);
		fprintf(outfile,"\n");
	}
}

	




