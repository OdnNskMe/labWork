#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
//������� ������� � ������ �������� ��������� � ���������� ��������� �� ���. 
//� �������������� ������� ����� ��� ��������� ��������� � ������.
bool seachWords(char str, char subStr)
{
	return(subStr != '\0'&&str != '\0'&&str == subStr);
}

int findstr(char* str, char* subStr, int* index)
{
	int len = strlen(str);
	int lenSub = strlen(subStr);
	if (len > lenSub)
	{
		for (int i = 0, j =0; i < len && j < lenSub; i++)
		{
			if (seachWords(*(str + i), *(subStr + j)))
			{
				j++;
			}
			else j = 0;
			if (j == lenSub)
			{
				*index +=1;//�������� �������� ����� ��� ������� �� �����
				printf("���������� � %d �������\n", (i-j+1));
				if (*(str+i+lenSub)!='\0')
					j = 0;
			}
		}
	}
	return -1;	
}

void main()
{	
	system("color F0 ");
	setlocale(LC_ALL, "Rus");
	char Array[100] = "���werwerw����werwerwe";
	char ArrayTest[35] = "wer";
	int index = 0;
	printf("�������� ������ \n%s\n", Array);
	printf("������� ������ \n%s\n", ArrayTest);
	findstr(Array, ArrayTest,&index);	
	printf("����� %d ����������\n",index);
}