#include <iostream>
#include<cmath>
#include<stdio.h>

using namespace std;

//Define the function f(x)

float f(float x){

	return exp(-x)*cos(x)*cos(x);
}


int main(){
	
	FILE *outfile;
	outfile = fopen("max_le_hw3_results.txt","a");

	float l_bound,u_bound,n_intervals, height,i,A=0,B=0,numeric,analytic,pi,rel_error_percent, max_interval; 
	fprintf(outfile,"\n");
	fprintf(outfile,"----------------------------------------------------------\n");
	fprintf(outfile,"Question 2: TRAPEZOIDAL METHOD \n");
	cout << "Given f(x) = (e^-x)*(cos(x))*(cos(x)) " << endl;
	cout << "Enter lower bound = " << endl;
	cin >> l_bound;
	fprintf(outfile,"Lower bound is %4.3f \n",l_bound);
	pi = 4.0*atan(1.0);
	u_bound = pi;
	fprintf(outfile,"Upper bound is %4.3f (real value for pi is coded)\n",u_bound);
	analytic = 0.6 - (0.6)*(exp(-1.0*pi));
	max_interval = 0;

	cout << "Enter max interval = " << endl;
	cin >> max_interval;
	fprintf(outfile,"Max interval is  %4.3f \n",max_interval);
	
	printf("Integration results are: \n");
	printf("n \t|Area \t\t| Numeric \t|Percent relative error \n");
	fprintf(outfile,"Integration results are: \n");
	fprintf(outfile,"n \t|Area \t\t| Numeric \t|Percent relative error \n");
	
	printf("------------------------------------------------------\n");
	fprintf(outfile,"--------------------------------------------------------------------\n");
	

	//Solving Trapezoidal 
	
	for (int n_intervals = 1; n_intervals  <= max_interval; n_intervals *=2){

	height = (u_bound - l_bound)/n_intervals; 
	A = 0;

		for (i = 1; i<=(n_intervals-1); i++){
	
		A = A+2.0*f(l_bound+(i*height));

		}

		numeric = (height/2.0)*(f(l_bound) + A + f(u_bound));
		rel_error_percent = ((numeric-analytic)/(analytic))*100.00;
		
		printf("%4.0d \t| %7.3f \t| %11.7f \t| %8.4e \n", n_intervals, A,numeric, rel_error_percent);
		fprintf(outfile,"%4.0d \t| %7.3f \t| %11.7f \t| %8.4e \n",n_intervals, A,numeric, rel_error_percent);

	}
	//Print 

	printf("The value of the integral of f(x) = %4.7f .\n", numeric);
	printf("The percent relative error = %4.4e %%.\n", rel_error_percent);
	fprintf(outfile,"The value of the integral of f(x) = %4.7f .\n", numeric);
	fprintf(outfile,"The percent relative error = %4.4e %%.\n", rel_error_percent);


	return 0;


}

