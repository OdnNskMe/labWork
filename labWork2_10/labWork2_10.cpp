#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
//Функция находит в строке самое первое (по алфавиту) слово. 
//С ее помощью реализовать размещение слов в выходной строке в алфавитном порядке.

//проверка на букву
bool isLetter(char c)
{
	return ((c >= 'А'&& c <= 'Я') || (c >= 'а' && c <= 'я'));
}
// расчет параметров для выделения объема памяти
void lenOfWords(char* str, int* wor, int* let, int* maxLW)
{	
	*let = strlen(str);//кол-во букв	
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
//сортировка массива строк
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
//слияние двухмерного массива в одномерный 
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
	*(str2 + z) = '\0';//под вопросом
}
//из одномерного в двумерный массив
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
	int words = 0; //кол-во слов
	int letters = 0;
	int maxLenOfWord = 0;

	lenOfWords(str,&words,&letters,&maxLenOfWord);// перевел в функцию

	char** arrayWords = (char**)malloc(sizeof(char*) * words);//создан массив заголовочный на кол-во слов
	for (int i = 0; i < words; i++)
	{
		*(arrayWords+i) = (char*)malloc(sizeof(char) * maxLenOfWord);//выделяем память для строк по кол-ву букв максимального размера слова
	}
	
	secondArrayWord(arrayWords,str,letters);//из одномерного массива двух мерный
	sort(arrayWords,words);// сортировка строк по алф
	merger(arrayWords,str, words, maxLenOfWord);//сливаем в одну строку
	
	//освободим память
	for (int i = 0; i<words; i++)
	{
		free(*(arrayWords+i));
	}	 
	free(arrayWords);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	char Array[50] = "Банан Вишня груша Яблоко Тыква А Дыня бобр";
	printf("%s\n", Array);	
	sortWords(Array);	
	printf("%s", Array);
}