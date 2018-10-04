#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
float function_f(float x);


int main(){
	
	
	FILE *outfile;
	outfile = fopen("max_le_hw3_results.txt","a");

	float x0, x_minus1, n_iter, x , error, f_prime;
	

	cout << "Enter the two initial guesses" << endl;
	cin >> x0;
	cin >> x_minus1;
	

	cout << " Enter number of iterations" << endl;
	cin >> n_iter;
	
	/*Use fprintf to do headers */ 
	fprintf(outfile,"\n");
	fprintf(outfile,"----------------------------------------------------------\n");
	fprintf(outfile,"Question 1: SECANT METHOD \n");
	fprintf(outfile,"Given f(x) = x^3 - 8x^2 + 6x + 6 \n");
	fprintf(outfile,"Initial guesses are: %4.3f and %4.3f \n", x0, x_minus1);
	fprintf(outfile,"Number of iteration is %4.3f \n" , n_iter);
	
	printf("n \t|x_minus1 \t| x0 \t | Relative percent error (%%) \n");
	fprintf(outfile,"n \t|x_minus1 \t|x0 \t| Relative percent error(%%) \n");
	printf("--------------------------------------------------------------\n");
	fprintf(outfile,"----------------------------------------------------------\n");
	
	error = 0;
	for (int n = 1; n<=n_iter ; n++){
	
	f_prime = (function_f(x0)-function_f(x_minus1))/(x0 - x_minus1);
	x = x0 - (function_f(x0))/(f_prime);
	error = 100*fabs((x-x0)/x);

	printf("%d \t|%.3f \t\t|%.3f   |%7.4f \n",n,x_minus1,x0,error);
	fprintf(outfile,"%d \t|%.3f \t\t|%.3f \t|%7.4f \n",n,x_minus1,x0,error);
	
	
	cout << endl;
	
	x_minus1 = x0;
	x0 = x;

	}

	printf("Root of f(x) = 0 is %.4f \n", x);
	fprintf(outfile,"Root of f(x) = 0 is %.4f \n", x);
	printf("The percent relative error = %4.4f %%.\n", error);
	fprintf(outfile, "The percent relative error = %4.4f %%.\n",error);
	fclose(outfile);
	return 0;


}







float function_f (float x){
	float f;
	f= x*x*x - 8*x*x + 6*x + 6;
	return f;
}




