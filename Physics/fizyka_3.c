#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
/*
r(t + dt) = -r(t-dt) + 2r(t) + a(t)*dt^2
x0 = PODANE
x1 = Euler
x2 = -x0 + 2x1 + a*dt^2
x3 = -x1 + 2x2 + a*dt^2

V = (r(t+dt)-r(t-dt))/2dt
V1 = (x2-x0)/2dt
*/

double toRadians(double degrees) { return degrees * PI / 180.0; }

void main()
{
	double x0 = 0, x, y0 = 5, y, kat = 50, V0 = 25, Vx, Vy, ax = 0; 
	double g = -9.81;
	double t = 0;
	const double dt = .01;
	double temp;
	FILE * output = NULL;
	
	Vx = V0 * cos(toRadians(kat));
	Vy = V0 * sin(toRadians(kat));
	
	output = fopen("C:\\Users\\pk\\Desktop\\output.txt", "w");
	fprintf(output, "     t           x           y           Vx           Vy\n%10f  %10f  %10f  %10f  %10f\n", t, x0, y0, Vx, Vy);
	x = x0 + Vx*dt;
	y = y0 + Vy*dt;
	Vx = Vx + ax*dt;
	Vy = Vy + g*dt;
	t+=dt;
	fprintf(output, "%10f  %10f  %10f  %10f  %10f\n", t, x, y, Vx, Vy);
	
	while(y >= 0)
	{
		temp = x;
		x = -x0 + 2*x + ax*dt*dt;
		Vx = (x-x0)/(2*dt);//w poprzednim kroku czasowym
		x0 = temp;
		
		temp = y;
		y = -y0 + 2*y + g*dt*dt;
		Vy = (y-y0)/(2*dt);//w poprzednim kroku czasowym
		y0 = temp;
		
		t+=dt;
		fprintf(output, "%10f  %10f  %10f  %10f  %10f\n", t, x, y, Vx, Vy);
	}
	
	fclose(output);
}
