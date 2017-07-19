#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
//������� ������� � ������ ����� ������ (�� ��������) �����. 
//� �� ������� ����������� ���������� ���� � �������� ������ � ���������� �������.

//�������� �� �����
bool isLetter(char c)
{
	return ((c >= '�'&& c <= '�') || (c >= '�' && c <= '�'));
}
// ������ ���������� ��� ��������� ������ ������
void lenOfWords(char* str, int* wor, int* let, int* maxLW)
{	
	*let = strlen(str);//���-�� ����	
	int lenOfWord = 0;
	for (int i = 0; i<*let; i++)
	{
		if (isLetter(*(str + i)))
		{
			if (i == 0 || !isLetter(*(str + i - 1)))
			{
				*wor+=1;
				lenOfWord = 0;
			}
			lenOfWord++;
			if (lenOfWord > *maxLW)
				*maxLW = lenOfWord;
		}
	}
	*maxLW+=1;
}
//���������� ������� �����
void sort(char** str, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(*(str + j), *(str + min))<0)
			{
				min = j;
			}
		}
		if (i != min)
		{
			char* arrayWordsBuff = *(str + i);
			*(str + i) = *(str + min);
			*(str + min) = arrayWordsBuff;
		}
	}
}
//������� ����������� ������� � ���������� 
void merger(char** str1, char* str2, int n, int maxLenWord)
{
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < maxLenWord && str1[i][j] != '\0'; j++)
		{
			*(str2 + z) = str1[i][j];
			z++;
		}
		*(str2 + z) = ' ';
		z++;
	}
	*(str2 + z) = '\0';//��� ��������
}
//�� ����������� � ��������� ������
void secondArrayWord(char** str1, char* str2, int n)
{
	for (int i = 0, currentWord = 0, currentLetter = 0; i<n; i++)
	{
		if (isLetter(*(str2 + i)))
		{
			if (i != 0 && !isLetter(*(str2 + i - 1)))
			{
				str1[currentWord][currentLetter] = '\0';
				currentWord++;
				currentLetter = 0;
			}
			str1[currentWord][currentLetter++] = *(str2 + i);
		}
		if (*(str2 + i + 1) == '\0')
		{
			str1[currentWord][currentLetter] = '\0';
		}
	}
}

void sortWords(char* str)
{		
	int words = 0; //���-�� ����
	int letters = 0;
	int maxLenOfWord = 0;

	lenOfWords(str,&words,&letters,&maxLenOfWord);// ������� � �������

	char** arrayWords = (char**)malloc(sizeof(char*) * words);//������ ������ ������������ �� ���-�� ����
	for (int i = 0; i < words; i++)
	{
		*(arrayWords+i) = (char*)malloc(sizeof(char) * maxLenOfWord);//�������� ������ ��� ����� �� ���-�� ���� ������������� ������� �����
	}
	
	secondArrayWord(arrayWords,str,letters);//�� ����������� ������� ���� ������
	sort(arrayWords,words);// ���������� ����� �� ���
	merger(arrayWords,str, words, maxLenOfWord);//������� � ���� ������
	
	//��������� ������
	for (int i = 0; i<words; i++)
	{
		free(*(arrayWords+i));
	}	 
	free(arrayWords);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	char Array[50] = "����� ����� ����� ������ ����� � ���� ����";
	printf("%s\n", Array);	
	sortWords(Array);	
	printf("%s", Array);
}