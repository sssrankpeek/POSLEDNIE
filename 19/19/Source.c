#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<io.h>
#include<math.h>
typedef struct{
	char surname[20];
	int day;
	int month;
	int year;
	char place[20];
	char position[20];
	float game;
	int ycard;
} P;
int writefile(int size)
{
	P A;
	FILE* ot;
	char name[20] = "footballers.txt";
	ot = fopen(name,"w");
	if ((ot = fopen(name, "wt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		printf("\nВведите фамилию игрока: ");
		scanf(" %s", A.surname);
		printf("\nВведите день рождения игрока: ");
		scanf(" %d%d%d", &A.day, &A.month, &A.year);
		printf("\nВведите место рождения игрока: ");
		scanf(" %s", A.place);
		printf("\nВведите позицию игрока: ");
		scanf(" %s", A.position);
		printf("\nВведите сыгранное количество игр: ");
		scanf(" %f", &A.game);
		printf("\nВведите количество полученных жёлтых карт: ");
		scanf(" %d", &A.ycard);
		fprintf(ot, "Фамилия: %s, Дата рождения: %d.%d.%d, Место рождения: %s, Позиция: %s, Игры: %f, Карточки: %d\n", A.surname, A.day, A.month, A.year, A.place, A.position, A.game, A.ycard);
	}
	fclose(ot);
	return 1;
}
float F(float x)
{
	float y = pow(2, x) - 2 * x * x - 1;
	return y;
}
void main()
{
	setlocale(LC_ALL, "RUS");
	char fname[20] = "number.txt";
	float a = 0;
	FILE* out;
	out = fopen("number.txt", "w");
	puts("Создание файла");
	if ((out = fopen(fname, "wt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	fprintf(out,"%d\n",5);
	fprintf(out,"%g\n", 12.56);
	fclose(out);
	char fname2[20] = "temp.txt";
	FILE* tab;
	float ARG, FUNC, tabu;
	int q=0;
	printf("\ny=2^x-2x^2-1");
	printf("\nвведите шаг табуляции функции:");
	scanf("%f", &tabu);
	printf("\nДля вывода результатов в старый файл нажмите 1, для вывода в новый нажмите 2");
	scanf("%d",&q);
	switch (q)
	{
	case 1:
		out = fopen(fname, "a");
		if ((out = fopen(fname, "a")) == NULL)
		{
			printf("Ошибка открытия файла для записи");
			return 0;
		}
		for (ARG = 2; ARG <= 4; ARG += tabu)
		{
			FUNC = F(ARG);
			fprintf(out, "%f\n", FUNC);
		}
		fclose(out);
		break;
	case 2:
		tab = fopen("temp.txt", "w");
		puts("Создание файла");
		if ((tab = fopen(fname2, "wt")) == NULL)
		{
			printf("Ошибка открытия файла для записи");
			return 0;
		}
		for (ARG = 2; ARG <= 4; ARG += tabu)
		{
			FUNC = F(ARG);
			fprintf(tab, "%f\n", FUNC);
		}
		fclose(tab);
		break;
	}
	writefile(2);
}
