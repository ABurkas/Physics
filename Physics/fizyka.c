#include <stdio.h>
#include <math.h>
#define N 1000
/*
Input: Vo, m, g, h
Output: s, Vk
*/
void fprintT(FILE *output, char c, float t, float deltaT, const float T[])
{
	fprintf(output, "%c(t):\n", c);
	for(int i = 0; i < (t/deltaT); i++)
	{
		fprintf(output, "%f\n", T[i]);
	} fprintf(output, "\n");
}
void printT(char c, float t, float deltaT, const float T[])
{
	printf("%c(t)[", c);
	int i;
	for(i = 0; i < (t/deltaT)-1; i++)
	{
		printf("%f, ", T[i]);
	} printf("%f]\n", T[i]);
}
int main()
{
     float Vo, m, g, h, deltaT;
     float s, Vk, t, Ek, kat, x[N], V[N], E[N], Y[N];
     FILE *output;
     
     printf("Vo = "); scanf("%f", &Vo);
     printf("m = "); scanf("%f", &m);
     printf("g = "); scanf("%f", &g);
     printf("h = "); scanf("%f", &h);
     printf("deltaT = "); scanf("%f", &deltaT);
     
     //h = (at^2)/2
     
     t = sqrt((2*h)/g);
     
     s = Vo * t;
     
     //Vk = sqrt(Vo^2 + Vy^2)
     //Vy = g * t
     
     Vk = sqrt(pow(Vo, 2) + pow((g * t), 2));
     
     //Ek = (m*V^2)/2
     
     Ek = (m * pow(Vk, 2)) / 2;
     
     //kat Vy Vk cos = b/c = Vy/Vk
     kat=acos((g*t)/Vk);
     
     output = fopen("C:\\Users\\Natan\\Desktop\\output.txt", "w");
     fprintf(output, "t = %f\ns = %f\nVk = %f\nEk = %f\nkat=%f(w radianach)\n\n", t, s, Vk, Ek, kat);
     printf("t = %f\ns = %f\nVk = %f\nEk = %f\nkat=%f(w radianach)\n\n\n", t, s, Vk, Ek, kat);
     
     for(int i = 0; i < t/deltaT; i++) x[i] = Vo * (deltaT * i);
     fprintT(output, 'x', t, deltaT, x);
     //printT('x', t, deltaT, x);
     
     for(int i = 0; i < t/deltaT; i++) V[i] = sqrt(pow(Vo, 2) + pow((g * (deltaT * i)), 2));
     fprintT(output, 'V', t, deltaT, V);
	 //printT('V', t, deltaT, V);
     
     for(int i = 0; i < t/deltaT; i++) E[i] = (m * pow(V[i], 2)) / 2;
     fprintT(output, 'E', t, deltaT, E);
	 //printT('E', t, deltaT, E);
     
     for(int i = 0; i < t/deltaT; i++) Y[i] = h - ((g * pow((deltaT * i), 2))/2);
     fprintT(output, 'Y', t, deltaT, Y);
	 //printT('Y', t, deltaT, Y);
	 
	 fclose(output);
	 
     return 0;
}
