#include <stdio.h>
#include <math.h>
#define PI 3.14159265359
/*
V(t + dt) = V(t) + a(t)*dt
r(t + dt) = r(t) + V(t)*dt
*/

double toRadians(double degrees) { return degrees * PI / 180.0; }

void main()
{
	double kat = 60, V = 20;
	double g = -9.80665, a = 0;
	double Vx, Vy, x = 0, y = 0, t = 0;
	double dt = .000001;
	FILE * output = NULL;
	
	Vx = V * cos(toRadians(kat));
	Vy = V * sin(toRadians(kat));
	
	output = fopen("C:\\Users\\pk\\Desktop\\output.txt", "w");
	
	fprintf(output, "    t          x          y          Vx          Vy\n", t, Vx, Vy, x, y);
	fprintf(output, "%f   %f   %f   %f   %f\n", t, x, y, Vx, Vy);
	
	while(y >= 0)
	{
		x = x + Vx*dt;
		y = y + Vy*dt;
		
		Vx = Vx + a*dt;
		Vy = Vy + g*dt;
		
		t += dt;
		
		fprintf(output, "%f   %f   %f   %f   %f\n", t, x, y, Vx, Vy);
	}
	
	fclose(output);
}
