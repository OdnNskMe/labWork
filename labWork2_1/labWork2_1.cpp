#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
//Функция находит в строке заданную подстроку и возвращает указатель на нее. 
//С использованием функции найти все вхождения подстроки в строке.
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
				*index +=1;//передаем значения входа или выводим на экран
				printf("совпадение с %d символа\n", (i-j+1));
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
	char Array[100] = "тйуwerwerwнгегwerwerwe";
	char ArrayTest[35] = "wer";
	int index = 0;
	printf("исходная строка \n%s\n", Array);
	printf("искомая строка \n%s\n", ArrayTest);
	findstr(Array, ArrayTest,&index);	
	printf("всего %d повторений\n",index);
}