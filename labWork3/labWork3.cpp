#include <stdio.h>
#include <conio.h>

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

int main()
{
	const int n = 8;
	char str1[n] = "ABc1450";
	char str2[n];
	int a = stringToDigit(str1);
	digitToString(a, str2, n);
	printf("%s\n%d\n",str1, a);
	printf("%s\n",str2);
	_getch();

}