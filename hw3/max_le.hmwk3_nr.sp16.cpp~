#include <iostream>
#include<stdio.h>
#include <cmath>
double function_g(double x);
double function_f(double x);
double derivative_f(double x);

using namespace std;

int main(){

	
	FILE *outfile;
	outfile = fopen("max_le_hw3_results.txt","a");
	double x0;
	cout <<"Enter initial guess " << endl;
	cin >> x0;
	fprintf(outfile,"\n");
	fprintf(outfile,"----------------------------------------------------------\n");
	fprintf(outfile,"Question 1: NEWTON-RAPHSON's METHOD \n");
	fprintf(outfile,"Given f(x) = x^3 - 8x^2 + 6x + 6 \n");
	fprintf(outfile, "Initial guess is %4.3f \n", x0);
	double error, tolerance = 1e-6, x1;
	int ini_iter, max_iter;
	cout << "Enter number of iterations" << endl;
	cin >> max_iter;
	fprintf(outfile,"Number of iteration is %d \n" , max_iter);
	ini_iter = 1;
	error = tolerance + 1;
	fprintf(outfile,"\n");
	printf("n \t|x0 \t|x \t| Relative error(%%)");
	fprintf(outfile,"n \t|x0 \t|x\t| Relative error(%%) \n");
	cout << endl;
	printf("--------------------------------------\n");
	fprintf(outfile,"--------------------------------------\n");
	
	for (int n = 1; n<=max_iter; n++){

	cout << endl;
	x1 = x0- function_f(x0)/derivative_f(x0);
	error = (x1-x0)/x0;
	error = fabs(error)*100;
	printf("%d \t|%4.3f \t|%4.3f \t|  %7.4e",n, x0, x1, error);
	fprintf(outfile,"%d \t|%4.3f \t|%4.3f \t|  %7.4e \n",n,x0, x1,error);
	x0 = x1;
	}
	

	if (error <= tolerance ){
	printf("\n");
	fprintf(outfile,"\n");
	printf("The root of f(x) = 0 is %4.3f \n" , x0);
	fprintf(outfile, "The root of f(x)=0 is %4.3f \n", x0);
	printf("The percent relative error = %7.4e %%.\n", error);
	fprintf(outfile, "The percent relative error = %7.4e %%.\n",error);
	}else{
	cout << "Solution diverges \n";
	fprintf(outfile, "Solution diverges \n");
	}
	fclose(outfile);
	return 0;
}

double function_g(double x){
	double g;
	g = 1/6*(x*x*x-8*x*x + 6);
	return g;
}

double function_f (double x){
	double f;
	f= x*x*x - 8*x*x + 6*x + 6;
	return f;
}


double derivative_f(double x){
	double f_prime;
	f_prime= 3*x*x-16*x+6;
	return f_prime;
}

