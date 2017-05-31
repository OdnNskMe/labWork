#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
double arctg(double x)
{
	double cps = 0.0001;// ��������
	double S = 0; // ��������� ��������
	double n = 1; //��� ����
	double Sn = x;	
	while (fabs(Sn) >= cps)// ������� ��������
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
	double x = 0.1;// �������� �������� ��������� �� 0,1
	do {
		printf("arc tangent | of %.2f is =  %f | math =  %f |\n", x , arctg(x), atan(x));
		x += 0.1; //��� ��������� ���������
	} while (x <= 1.0);  // �������� �������� ��������� �� 1
	
	_getch();
}