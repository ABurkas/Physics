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

r(t+dt) = r(t) + v(t)dt + 1/2(a(t))dt^2
V(t + dt) = V(t) + 1/2(a(t+dt)+a(t))dt
*/

double toRadians(double degrees) { return degrees * PI / 180.0; }

void main()
{
	double x, y = 114, kat = 40, V0 = 15, Vx, Vy, ax = 0; 
	double g = -9.81;
	double t = 0;
	const double dt = .1;
	FILE * output = NULL;
	
	Vx = V0 * cos(toRadians(kat));
	Vy = V0 * sin(toRadians(kat));
	
	output = fopen("C:\\Users\\pk\\Desktop\\output.txt", "w");
	fprintf(output, "     t           x           y           Vx           Vy\n%10f  %10f  %10f  %10f  %10f\n", t, x, y, Vx, Vy);
	while(y >= 0)
	{
		x = x + Vx*dt + (ax*dt*dt)/2;
		y = y + Vy*dt + (g*dt*dt)/2;
		
		Vx = Vx + ax*dt;
		Vy = Vy + g*dt;
		
		t+=dt;
		fprintf(output, "%10f  %10f  %10f  %10f  %10f\n", t, x, y, Vx, Vy);
	}
	
	fclose(output);
}
