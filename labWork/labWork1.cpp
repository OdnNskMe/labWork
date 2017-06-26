// labWork.cpp : Defines the entry point for the console application.
//
//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdlib.h>
#include <math.h>

//сделаем меню
void menu()
{
	printf("----------\n");
	printf("1. Work_Max_Repet_Lab_1\n");
	printf("2. Work_Average_Arithmetic_Lab_2\n");
	printf("3. Work_MinAllKrat_Lab_6_7\n");
	printf("4. Work_Lab_9\n");
	printf("0. Exit\n");
	printf("----------\n");
}

//формируем массив случайных чисел
void masNumb(int a[], int n, int z)// массив не корректно т.к. размерность идет с нуля а не 
{
	for (int i = 0; i < n; i++)// N задает размер массива, цикл повторяется пока массив не заполнится
	{
		a[i] = rand() % z;//берем текушую ячейку массива и заполняем случайным числом.ограничение случайных чисел до Z
	}
}
//выводим массив на экран
void outPut(int a[], int n)
{
	for (int i = 0; i < n; i++)//берем текушее значение масиива и выводим его на экран, делаем это n раз т.к. n это размер массива
		{
			printf("%d ", a[i]);//выводим на экран текушее значение массива		
		}
		printf("\n");//пустая строчка после массива		
}
//среднее арифметическое
int Work_Average_Arithmetic(int a[], int v[], int n)
{
	int sum =0;//сумма массива
	int average = 0;//сред арифм
	int y = n;
	int c = 0;//соответсвие искомому в массиве
	for (int i = 0; i < n; i++)
	{		
		sum = sum + a[i];//переменная счетчик
		average = sum / n;
	}
	for (int i = 0; i < n; i++)
		{
		v[i] = abs(average-a[i]);
			if (v[i]<y)
			{
				y = v[i];
				c = a[i];
			}
		}	
	//printf("----------\n");
	//printf("Average = %d | %d \n", average, c);//вывод на экран значения сред арифмет
	return c;
}
//наиболее повторяющееся число в массиве
int Work_Max_Repet(int a[],int v[],int n)
{	
	int d = 0;
	int g = 0;
	for (int i = 0; i < n; i++)//цикл в котором переменной S присваиваем значение текущего значения массива и будем сравнивать с остальным массивом
	{	
		int schet = 0;//переменная посчет повторений
		int s = a[i];// переменная. присваиваем тек знач массива					
			for (int i = 0; i < n; i++)//цикл сравнения переменной с каждой ячейкой массива
			{
				if (s == a[i])
				{
					schet++;//счет если повтор значения					
				}				
					v[i] = schet;//массив из кол-ва повторений		
					
					if (v[i] > d)//условие максимального повтора
					{
						d = v[i];
						g = a[i];
					}					
			}		
	}
	/*printf("----------\n");
	printf("max povtor = %d | %d\n", g, d);*/
	return g;
}
//******** это блок функций для нахождения NOK и NOD **********
	int NOD(int j, int b) // Поиск наибольшего общего делителя
	{	
		int q = j;
		int w = b;
		int c = 1;
		if (q != w)
		{
			while (q >= 1 && w >= 1 && q != w)
			{
				if (q < w)
				{					
					c = w%q;
					if (c > 0)
					{
						w = q;
						q = c;
					}
					else
					{
						c = q;
						break;
					}
				}
				else if (q > w)
				{
					c = q%w;
					if (c > 0)
					{
						q = w;
						w = c;
					}
					else
					{
						c = w;
						break;
					}
				}
				else
				{
					printf("???\n");
				}
			}
		}
		else
		{
			c = q;			
		}
		return c;		
	}

	int NOK(int j, int b) // Поиск наименьшего общего кратного
	{
		int m = j * b / NOD(j, b);
		return m;
	}
//*********************************
	
// находим наименьшее общее кратное массива
int Work_NOK(int a[], int n)
{	
	int answer = 0;	
	for (int i = 0; i < n; i++)
	{			
		for (int i = 0; i < n-1; i++)
		{			
			answer = NOK(a[i], a[i+1]);
		}			
	}
	/*printf("----------\n");
	printf("Work_HOK = %d \n", answer);*/
	return answer;
}

int Lab_9(int a[], int n)
{
	int sum1 = 0;
	int sum2 = 0;
	int k = n/2;
	for (int i = 0; i <= n / 2; i++) 
	{
		sum1 = sum1 + a[i];		
	}
	for (int i = n / 2 + 1 ; i < n; i++) 
	{
		sum2 = sum2 + a[i]; 
	}
		
	if (sum1 > sum2) 
	{

		while (sum1 - sum2 > a[k])
		{
			sum1 = sum1 - a[k];
			sum2 = sum2 + a[k];
			k-=1;
		}		
	}
	else 
	{			
		while(sum2 - sum1 > a[k+1])
		{
			sum1 = sum1 + a[k];
			sum2 = sum2 - a[k];
			k+=1;
		}
		
	}
	
	/*printf("----------\n");
	printf("Work_Lab_9 sum1 =%d sum2=%d k=%d\n", sum1, sum2,k);*/
	return k;
}

void Print(char *title, int result)
{
	printf("%s = %d\n", title, result);
}

int main()
{
	const int N = 10;//размерность массива
	const int Z = 10;//размер рандома	
	int A[N];
	int V[N];
	int action;//выбор пункта меню
	int result= 0;
	do
	{
		menu();
		scanf_s("%d", &action);//выбор пункта меню
		masNumb(A, N, Z);
		outPut(A, N);
		switch (action)
		{
		case 1:			
			{
				int result = Work_Max_Repet(A, V, N);
				Print("max povtor", result);
			}
			/*printf("max povtor = %d\n", Work_Max_Repet(A, V, N));
			Work_Max_Repet(A, V, N);*/
			break;
		case 2:
			{
				int result = Work_Average_Arithmetic(A, V, N);
				Print("Average", result); 
			}
			/*Work_Average_Arithmetic(A, V, N);
			printf("Average = %d \n", Work_Average_Arithmetic(A, V, N));*/
			break;
		case 3:
			{
				int result = Work_NOK(A, N);
				Print("Work_HOK", result);
			}
			/*Work_NOK(A, N);
			printf("Work_HOK = %d \n", Work_NOK(A, N));*/
			break;		
		case 4:
			{
				int result = Lab_9(A, N);
				Print("Work_Lab_9", result);
			}
			/*printf("Work_Lab_9 k=%d\n", Lab_9(A, N));
			Lab_9(A, N);*/
			break;		
		default:
			break;
		}
	} while (action != 0);

    return 0;
}

