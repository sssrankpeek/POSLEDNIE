#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	FILE* zima;
	zima = fopen("winter.txt", "r");
	if ((zima = fopen("winter.txt", "r")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	char str[100];
	int counter = 1;
	while (!feof(zima))
	{
		if (fgets(str, sizeof(str), zima) != NULL)
		{ 
			printf("%d.%s", counter,str);
			counter++;
		}
	}
	fclose(zima);
}