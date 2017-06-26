#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int*glass1, int*glass2)
{
	int glass3 = *glass1;
	*glass1 = *glass2;
	*glass2 = glass3;
}

void masNumb(int a[], int n, int z)// ������ �� ��������� �.�. ����������� ���� � ���� � �� 
{
	for (int i = 0; i < n; i++)// N ������ ������ �������, ���� ����������� ���� ������ �� ����������
	{
		a[i] = rand() % z;//����� ������� ������ ������� � ��������� ��������� ������.����������� ��������� ����� �� Z
	}
}
void masWorkB(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
//������� ������ �� �����
void outPut(int a[], int n, char*title)
{
	printf("--%s--\n", title);
	for (int i = 0; i < n; i++)//����� ������� �������� ������� � ������� ��� �� �����, ������ ��� n ��� �.�. n ��� ������ �������
	{
		printf("%d ", a[i]);//������� �� ����� ������� �������� �������		
	}
	printf("\n\n");//������ ������� ����� �������		
}

void Print(char *title1, int result1, char *title2, int result2, char *title3, int result3)
{
	printf("%s = %d\n %s = %d\n %s = %d\n", title1, result1, title2, result2, title3, result3);
}

void menu()
{
	printf("----sort----\n");
	printf("1. Bubble\n");
	printf("2. Shaker\n");
	printf("3. Select\n");
	printf("4. Merge\n");
	printf("5. Quick\n");
	printf("0. Exit\n");
	printf("----------\n");
}

void sortBubble(int A[], int n, time_t &time, int &countConpare, int &countSwap)
{		
	bool isSwap;
	do 
	{
		isSwap = false;
		int lastSwap = 0;
		for (int i = 0; i < n - 1; i++)
		{			
			if (A[i] > A[i + 1])
			{
				countSwap++;
				swap(&A[i], &A[i + 1]);
				isSwap = true;
				lastSwap = i + 1;
				countConpare++;
			}			
		}
		n = lastSwap;
		countConpare++;		
	} while (isSwap);
	time = clock() - time;
}

void sortShaker(int A[], int n, time_t &time, int &countConpare, int &countSwap)
{	
	int a = 0, b = n, step = 1;
	while (b - a > 1)
	{		
		if (step == 1)
		{
			int last = a;
			for (int i = a; i < b - 1; i++)
			{				
				if (A[i] > A[i + 1])
				{
					countSwap++;
					swap(&A[i], &A[i + 1]);
					last = i + 1;
					countConpare++;
				}
			}
			b = last;
			countConpare++;
		}
		else
		{
			int last = b - 1;
			for (int i = b - 1; i > a; i--)
			{
				if (A[i - 1 > A[i]])
				{
					countSwap++;
					swap(&A[i-1], &A[i]);
					last = i-1;
					countConpare++;
				}
			}
			a = last;
		}
		step *= -1;
		countConpare++;
	}
	time = clock() - time;	
}

void sortSelect(int A[], int n, time_t &time, int &countConpare, int &countSwap)
{	
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{			
			if (A[j] < A[min])
			{
				countConpare++;
				min = j;
			}				
		}		
		if (i != min)
		{
			countSwap++;
			swap(&A[i], &A[min]);
			countConpare++;
		}
			
	}
	time = clock() - time;
}

void sortQuick(int A[], int a, int b, time_t &time, int &countConpare, int &countSwap)
{
	if ((b - a) > 1)
	{
		double sr = 0;
		for (int i = a; i < b; i++)
			sr += A[i];//������� ����� �������
		sr /= (b - a);//������� ������� �������
		//����� ����������
		int i = a;
		int j = b - 1;
		while (i<j)
		{			
			if (A[i] <= sr)
			{
				i++;
				countConpare++;
			}
			else
			{				
				if (A[j] > sr)
				{
					countConpare++;
					j--;
				}					
				else
				{
					countSwap++;
					swap(&A[i], &A[j]);
					countConpare++;
				}
				countConpare++;
			}
			countConpare++;
		}
		sortQuick(A, a, i, time, countConpare, countSwap);
		sortQuick(A, i, b, time, countConpare, countSwap);
	}
	time = clock() - time;	
}

void sortMerge(int A[], int a, int b, time_t &time, int &countConpare, int &countSwap)
{	
	if (b - a > 1)
	{
		int center = (a + b) / 2;
		sortMerge(A, a, center, time, countConpare, countSwap);
		sortMerge(A, center, b, time, countConpare, countSwap);
		int *Temp = new int[b - a];
		int i = 0;
		int j = 0;
		while (a + i < center&&center + j < b)
		{			
			if (A[a + i] < A[center + j])
			{
				Temp[i + j] = A[a + i];
				i++;
				countConpare++;
			}
			else
			{
				Temp[i + j] = A[center + j];
				j++;
				countConpare++;
			}
			countConpare++;
		}
		while (a + i < center)
		{
			Temp[i + j] = A[a + i];
			i++;
			countConpare++;
		}
		while (center + j < b)
		{
			Temp[i + j] = A[center + j];
			j++;
			countConpare++;
		}
		for (int i = 0; i < b-a; i++)
		{
			A[a + i] = Temp[i];
		}
		delete[]Temp;
	}
	time = clock() - time;
	
}

void main()
{
	const int N = 157;
	int Z = 100;
	int A[N];
	int B[N];
	int action;
	time_t time;
	int countConpare = 0;
	int countSwap = 0;

	masNumb(A, N, Z);
	outPut(A, N, "massiv");
	do {
		//outPut(A, N,"massiv");
		menu();		
		scanf_s("%d", &action);
		switch (action)
		{
		case(1):
		{	
			time = clock();
			countConpare = 0;
			countSwap = 0;
			masWorkB(A,B,N);
			sortBubble(B, N, time, countConpare, countSwap);
			outPut(B, N,"Bubble");
			Print("time_Bubble", time, "conpare_Bubble", countConpare, "swap_Bubble", countSwap);
		}
			break;
		case(2):
		{
			time = clock();
			countConpare = 0;
			countSwap = 0;
			masWorkB(A, B, N);
			sortShaker(B, N, time, countConpare, countSwap);
			outPut(B, N,"Sheker");
			Print("time_Shaker", time, "conpare_Shaker", countConpare, "swap_Shaker", countSwap);
		}
			break;
		case(3):
		{
			time = clock();
			countConpare = 0;
			countSwap = 0;
			masWorkB(A, B, N);
			sortSelect(B, N, time, countConpare, countSwap);
			outPut(B, N,"Select");
			Print("time_Select", time, "conpare_Select", countConpare, "swap_Select", countSwap);
		}
			break;
		case(4):
		{
			time = clock();
			countConpare = 0;
			countSwap = 0;
			masWorkB(A, B, N);
			sortMerge(B,0, N, time, countConpare, countSwap);
			outPut(B, N, "Merge");
			Print("time_Merge", time, "conpare_Merge", countConpare, "swap_Merge", countSwap);
		}
		break;
		case(5):
		{
			time = clock();
			countConpare = 0;
			countSwap = 0;
			masWorkB(A, B, N);
			sortQuick(B,0, N, time, countConpare, countSwap);
			outPut(B, N, "Quick");
			Print("time_Quick", time, "conpare_Quick", countConpare, "swap_Quick", countSwap);
		}
		break;

		default:
			break;
		}
		
	} while (action != 0);
}
