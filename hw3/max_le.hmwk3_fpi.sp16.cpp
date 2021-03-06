#include <stdio.h>
#include <math.h>
float function_g(float x);

int main() {
	FILE *outfile;
	outfile = fopen("max_le_hw3_results.txt","a");

	float x,b,x0,n_iter, c = 100.0;
	int j = 0;
	b=0;
	fprintf(outfile,"\n");
	fprintf(outfile,"----------------------------------------------------------\n");
	fprintf(outfile,"Question 1: FIXED POINT ITERATION METHOD \n");
	fprintf(outfile,"Given f(x) = x^3 - 8x^2 + 6x + 6 \n");
	printf("Please enter initial guess: \n");
	scanf("%f", &x0);
	fprintf(outfile, "Initial guess is %4.3f \n", x0);
	printf("Enter number of iterations: \n");
	scanf("%f",&n_iter);
	fprintf(outfile, "Number of iteration is %4.3f \n", n_iter);

	printf("\n Values of iterations are: \n");
	printf("n \t|x0 \t\t| x\t\t| Relative error (%%) \n");
	fprintf(outfile,"\n");
	fprintf(outfile,"n \t|x0 \t\t|  x \t\t | Relative error (%%) \n");
	fprintf(outfile,"--------------------------------------------------\n");	
	printf("-----------------------------------------------------------\n");
	for(int n=1;n<=n_iter;n++){
	
	x = function_g(x0);
	c = (x - x0)/x0;
	x = x0 - c;
	c = fabs(c)*100;
	
	printf("%d\t|%4.7f\t|%4.7f\t|  %7.4f \n",n,x0 , x , c);
	fprintf(outfile,"%d \t|%4.7f \t| %4.7f  | %7.4f \n",n, x0, x, c);
	x0 = x;	
	}
	
	printf("\n The root of f(x) = 0 is %4.3f \n" , x);
	fprintf(outfile, "The root of f(x)=0 is %4.3f \n", x);
	printf("The percent relative error = %4.4f %%.\n", c);
	fprintf(outfile, "The percent relative error = %4.4f %%.\n",c);
	fclose(outfile);	
	
}


float function_g(float x){
	float g;
	g = -(1.0/6.0)*(pow(x,3)-8.0*pow(x,2) + 6.0);
	//g = -6.0/(pow(x,2) -8.0*x + 6.0);	
	return g;
}



