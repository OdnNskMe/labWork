#include <stdio.h>
#include <conio.h>
#include <string.h>

int stringToDigit(char *c)
{
	int digit = 0;
	for (int i = 0; c[i] != '\0'; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			digit *= 10;
			digit += c[i] - '0';
		}				
	}
	return digit;
}


void revers(char *s)
{
	int j;
	for (j = 0; s[j] != '\0'; j++);
		j--;
	for (int i = 0; i < j; i++, j--)
	{
		char swap = s[i];
		s[i] = s[j];
		s[j] = swap;
	}
}

void digitToString(int digit, char *s,int n)
{
	int a = 0;
	int j = 0;
	while (digit!=0)
	{
		a = digit % 16;
		if (a > 9)
			s[j] = a + '7';
		else s[j] = a + '0';
		digit = digit / 16;
		j++;
	}
	s[j] = '\0';
	revers(s);
}
//для одного чар
void digitToStringForOne(int digit, char *s, int n)
{
	int a = 0;
		while (digit != 0)
		{
			a = digit % 16;
			if (a > 9)
				*s = a + '7';
			else *s = a + '0';
			digit = digit / 16;
		}
}

void findToDigit(char *str1, char *str2, int n)
{
	int digit = 0;
	for (int i = 0; str1[i] != '/0'; i++)
	{
		if (str1[i] >= '0' && str1[i] <= '9')
		{			
			str2[i] = str1[i];
			
		}
		else
		{

		}
	}

}

//находим и вырезаем то, что между внутрен {} скобками в строке
void findBraces(char *str1, char *str2)
{
	int b = 0;
	int maxb = 0;
	for (int i = 0; str1[i] != '}'; i++)
	{
		if (str1[i] == '{')
		{
			maxb = i;
		}
	}
	maxb++;

	for (int i = maxb, j = 0; str1[i] != '\0'; i++, j++)
	{
		str2[j] = str1[i];

		if (str1[i + 1] == '}')
		{
			int len = strlen(str2);
			for (int b = maxb; str1[b] != '\0'; b++)
				str1[b] = str1[b + len];
			break;
		}
	}
}

int main()
{
	const int n = 20;
	char str1[n] = "A11{2{31{i";
	char str2[n] = "";
	char str3[n] = "";
	//int a = stringToDigit(str1);
	//digitToString(a, str2, n);
	findToDigit(str1, str2,n);
	//printf("%s\n%d\n",str1, a);
	printf("%s\n",str2);
	
	//findBraces(str1, str3);
	//printf("%s\n", str1);
	//printf("%s\n", str3);
	_getch();

}