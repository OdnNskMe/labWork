#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
double arctg(double x)
{
	double cps = 0.0001;// точность
	double S = 0; // начальное значение
	double n = 1; //шаг ряда
	double Sn = x;	
	while (fabs(Sn) >= cps)// условие точности
	{
		S += Sn;
		double t = -(x*x*(2 * n - 1)) / (2 * n + 1);
		Sn = Sn*t;
		n++;		
	}
	return S;
}

int main()
{
	double x = 0.1;// диапазон значений аргумента от 0,1
	do {
		printf("arc tangent | of %.2f is =  %f | math =  %f |\n", x , arctg(x), atan(x));
		x += 0.1; //шаг изменения аргумента
	} while (x <= 1.0);  // диапазон значений аргумента до 1
	
	_getch();
}