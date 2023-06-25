#include <stdio.h>
//T = delta t (30)
// y(t+deltaT) = 
// V(t+T) = V(t) + a(t)*T
// r(t+T) = r(t)+V(t)*T

void fprintT(FILE *output, char c, double t, double dt, double *T)
{
	fprintf(output, "%c(t):\n", c);
	for(int i = 0; i < (t/dt); i++)
	{
		fprintf(output, "%f\n", T[i]);
	} fprintf(output, "\n");
}

void main()
{
	double g = -9.81, h = 100, V0 = 0;
	double t = 0;
	double *V, *y, *T;
	double dt = .0001;
	int i = 0;
	FILE *output = NULL;
	
	t = sqrt((2*h)/( (g<0) ? -g : g ));
	
	T = malloc( (int)((t/dt)+2) * sizeof(double) ); T[0] = 0;
	
	V = malloc( (int)((t/dt)+2) * sizeof(double) ); V[0] = V0;
	y = malloc( (int)((t/dt)+2) * sizeof(double) ); y[0] = h;
	
	printf("t	V	y\n");
	for(i = 1; i < (t/dt)+1; i++)
	{
		T[i] = T[i-1] + dt; printf("%f ", T[i-1]);
		V[i] = V[i-1] + g*dt; printf("%f ", V[i-1]);
		y[i] = y[i-1] + V[i]*dt; printf("%f\n", y[i-1]);
	}
	
	printf("%f ", T[i-1]);
	printf("%f ", V[i-1]);
	printf("%f\n", y[i-1]);
	
	output = fopen("C:\\Users\\pk\\Desktop\\output.txt", "w");
    
    fprintT(output, 't', t, dt, T);
    fprintT(output, 'V', t, dt, V);
    fprintT(output, 'y', t, dt, y);
    
    free(V);
    free(y);
    fclose(output);
}
