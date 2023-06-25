#include <stdio.h>
#include <math.h>

void main()
{
	double x = 0, y = 230, Vy = 0, m = 100, k = 10;
	double Ep = 0, Ek = 0;
	double g = -9.81;
	double Ky1, Ky2, Ky3, Ky4;
	double Kv1, Kv2, Kv3, Kv4; //O DZIWO JEST SZYBCIEJ na K1,K2,K3,K4
	double K1, K2, K3, K4;
	double t = 0, dt = .1;
	FILE * output = NULL;
	Ep = Ep = k*y*y/2;
	Ek = (m*Vy*Vy)/2;
	output = fopen("C:\\Users\\pk\\Desktop\\output.txt", "w");
	fprintf(output, "      t            y            Vy            Ep            Ek           Ec\n%12f  %12f  %12f  %12Lf  %12Lf  %12Lf\n", t, y, Vy, Ep, Ek, Ep+Ek);
	
	printf("%10f\n", sqrt(2*y/(g<0 ? -g:g)));
	printf("%10f\n", sqrt(2*y*(g<0 ? -g:g)));
	
	while(t <= 100)
	{
		//double _Vy;
		
		Ky1 = Vy*dt;
		Kv1 = ((-k)/m)*y*dt;
		Ky2 = (Vy + Kv1/2)*dt;
		Kv2 = ((-k)/m)*(y+(Ky1/2))*dt;
		Ky3 = (Vy + Kv2/2)*dt;
		Kv3 = ((-k)/m)*(y+(Ky2/2))*dt;
		Ky4 = (Vy + Kv3)*dt;
		Kv4 = ((-k)/m)*(y+(Ky3))*dt;
		
		/*K1 = ((-k)/m)*y*dt;
		K2 = ((-k)/m)*(y+)*dt;
		K3 = g*dt;
		K4 = g*dt;
		_Vy = Vy + (K1 + 2*K2 + 2*K3 + K4)/6;*/
		
		/*
		K4 = (Vy + K3)*dt;
		K3 = (Vy + K2/2)*dt;
		K2 = (Vy + K1/2)*dt;
		K1 = Vy*dt;
		*/
		//y = y + (K1 + 2*K2 + 2*K3 + K4)/6;
		//Vy = _Vy;
		
		y = y + (Ky1 + 2*Ky2 + 2*Ky3 + Ky4)/6;
		Vy = Vy + (Kv1 + 2*Kv2 + 2*Kv3 + Kv4)/6;
		
		Ep = k*y*y/2;
		Ek = (m*Vy*Vy)/2;
		t += dt;
		fprintf(output, "%12f  %12f  %12f  %12Lf  %12Lf  %12Lf\n", t, y, Vy, Ep, Ek, Ep+Ek);
	}
	printf("%12f   %12f   %12f\n", y, t, Vy);
	
	fclose(output);
}
