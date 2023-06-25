#include <stdio.h>
#include <math.h>

/*

RK4F5:
K1 = f(y,t)dt
K2 = f(y + 1/4K1, t + dt/4))dt
K3 = f(y+3/32K1 + 9/32K2, t+3/8dt)dt
K4 = f(y+1932/2197K1 - 7200/2197K2+7296/2197K3, t+12/13dt)dt
K5 = f(y+439/216K1-8K2+3680/513K3-845/4104K4, t+dt)dt
y(t+dt) = y(t) + 25/216K1+1408/2565K3+2197/4104K4-1/5K5
gdzie f(y, t) = y'(t)


*/

void main()
{
	double x = 0, y = 0, Vy = 0, m = 5, d = 80; //depth
	double Ep = 0, Ek = 0;
	double g = 9.81;
	//double Ky1, Ky2, Ky3, Ky4;
	//double Kv1, Kv2, Kv3, Kv4; //O DZIWO JEST SZYBCIEJ na K1,K2,K3,K4
	double K1, K2, K3, K4, K5;
	double t = 0, dt = .1;
	FILE * output = NULL;
	Ep = m*(g<0 ? -g : g)*(d-y);
	Ek = (m*Vy*Vy)/2;
	output = fopen("C:\\Users\\pk\\Desktop\\output.txt", "w");
	fprintf(output, "      t            y            Vy            Ep            Ek           Ec\n%12f  %12f  %12f  %12Lf  %12Lf  %12Lf\n", t, y, Vy, Ep, Ek, Ep+Ek);
	
	printf("%10f\n", sqrt(2*y/(g<0 ? -g:g)));
	printf("%10f\n", sqrt(2*y*(g<0 ? -g:g)));
	
	while(y < 80)
	{
		double _Vy;
		/*
		Ky1 = Vy*dt;
		Kv1 = ((-k)/m)*y*dt;
		Ky2 = (Vy + Kv1/2)*dt;
		Kv2 = ((-k)/m)*(y+(Ky1/2))*dt;
		Ky3 = (Vy + Kv2/2)*dt;
		Kv3 = ((-k)/m)*(y+(Ky2/2))*dt;
		Ky4 = (Vy + Kv3)*dt;
		Kv4 = ((-k)/m)*(y+(Ky3))*dt;
		*/
		K1 = g*dt;
		K2 = g*dt;
		K3 = g*dt;
		K4 = g*dt;
		K4 = g*dt;
		K5 = g*dt;
		_Vy = Vy + ((25*K1)/216)+((1408*K3)/2565)+((2197*K4)/4104)-(K5/5);
		
		K5 = (Vy + ((439*K1)/216) - (8*K2) + ((3680*K3)/513) - ((845*K4)/4104))*dt; 
		K4 = (Vy + ((1932*K1)/2197)-((7200*K2)/2197)+((7296*K3)/2197))*dt;
		K3 = (Vy + ((3*K1)/32)+((9*K2)/32))*dt;
		K2 = (Vy + (K1/4))*dt;
		K1 = Vy*dt;
		
		y = y + ((25*K1)/216)+((1408*K3)/2565)+((2197*K4)/4104)-(K5/5);
		Vy = _Vy;
		
		//y = y + (Ky1 + 2*Ky2 + 2*Ky3 + Ky4)/6;
		//Vy = Vy + (Kv1 + 2*Kv2 + 2*Kv3 + Kv4)/6;
		
		Ep = m*(g<0 ? -g : g)*(d-y);
		Ek = (m*Vy*Vy)/2;
		t += dt;
		fprintf(output, "%12f  %12f  %12f  %12Lf  %12Lf  %12Lf\n", t, y, Vy, Ep, Ek, Ep+Ek);
	}
	printf("%12f   %12f   %12f\n", y, t, Vy);
	
	fclose(output);
}
