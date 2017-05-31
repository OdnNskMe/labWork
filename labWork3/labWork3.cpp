#include <stdio.h>
#include <conio.h>
int digit(char *S, int n)
{
	for (int i = 0; S[i]!= '\0'; i++)
	{
		//int *B = new int[n];
		int hex = 0;
		if ('0' <= S[i] && S[i] <= '9')
		{
			hex = S[i]%16; 
			if (hex > 9)
			{
				hex += (int)'A' - 10;
			}
			else
			{
				hex += (int)'0';
			}		
			
		}
		return hex;
	}	
}

int main()
{
	const int n = 5;
	char S[n] = { 100,200,0xA3,200,500 };
	
	_getch();
}