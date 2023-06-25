#include <stdio.h>
#include <math.h>

/*

K1 = f(y, t)dt
K2 = f(y+K1/2, t+dt/2)dt
K3 = f(y+K2/2, t+d2/2)dt
K4 = f(y, K3, t+dt)dt
y(t+dt) = y(t) + 1/6(K1+2K2+2K3+K4) + O(dt^5)

f(y, t) = całka y(t)
*/

/*

Ky1 = Vy*dt
Kv1 = a*dt
Ky2 = (Vy + Kv1/2)dt
Kv2 = a*dt
Ky3 = (Vy + Kv2/2)dt
Kv3 = a*dt
Ky4 = (Vy + Kv3)dt
Kv4 = a*dt

y = y + 1/6(Ky1 + 2Ky2 + 2Ky3 + Ky4)
Vy = Vy + 1/6(Kv1 + 2Kv2 + 2Kv3 + K4)

Ep, Ek, Ec

*/

void main()
{
	double x = 0, y = 230, g = -9.81, Vy = 0, Ep = 0, Ek = 0, m = 2;
	//double Ky1, Ky2, Ky3, Ky4;
	//double Kv1, Kv2, Kv3, Kv4; //O DZIWO JEST SZYBCIEJ na K1,K2,K3,K4
	double K1, K2, K3, K4;
	double t = 0, dt = .1;
	FILE * output = NULL;
	Ep = m*(g<0 ? -g:g)*y;
	Ek = (m*Vy*Vy)/2;
	output = fopen("C:\\Users\\pk\\Desktop\\output.txt", "w");
	fprintf(output, "      t            y            Vy            Ep            Ek           Ec\n%12f  %12f  %12f  %12f  %12f  %12f\n", t, y, Vy, Ep, Ek, Ep+Ek);
	
	printf("%10f\n", sqrt(2*y/(g<0 ? -g:g)));
	printf("%10f\n", sqrt(2*y*(g<0 ? -g:g)));
	
	while(y >= 0)
	{
		double _Vy;
		/*
		Ky1 = Vy*dt;
		Kv1 = g*dt;
		Ky2 = (Vy + Kv1/2)*dt;
		Kv2 = g*dt;
		Ky3 = (Vy + Kv2/2)*dt;
		Kv3 = g*dt;
		Ky4 = (Vy + Kv3)*dt;
		Kv4 = g*dt;*/
		
		K1 = g*dt;
		K2 = g*dt;
		K3 = g*dt;
		K4 = g*dt;
		_Vy = Vy + (K1 + 2*K2 + 2*K3 + K4)/6;
		
		
		K4 = (Vy + K3)*dt;
		K3 = (Vy + K2/2)*dt;
		K2 = (Vy + K1/2)*dt;
		K1 = Vy*dt;
		
		y = y + (K1 + 2*K2 + 2*K3 + K4)/6;
		Vy = _Vy;
		
		//y = y + (Ky1 + 2*Ky2 + 2*Ky3 + Ky4)/6;
		//Vy = Vy + (Kv1 + 2*Kv2 + 2*Kv3 + Kv4)/6;
		
		Ep = m*(g<0 ? -g:g)*y;
		Ek = (m*Vy*Vy)/2;
		t += dt;
		fprintf(output, "%12f  %12f  %12f  %12f  %12f  %12f\n", t, y, Vy, Ep, Ek, Ep+Ek);
	}
	printf("%12f   %12f   %12f\n", y, t, Vy);
	
	fclose(output);
}
