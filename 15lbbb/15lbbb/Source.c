#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	int a[50][50];
	int n, m, i, j, r = 0,min=1000;
	srand(time(NULL));
	printf("Введите количество строк: ");
	scanf("%d",&n);
	printf("\nВведите количество столбцов: ");
	scanf("%d",&m);
	printf("\nВ какой строке хотите найти минимальный? ");
	scanf("%d", &r);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a[i][j] = i + j;
			printf("%d ", a[i][j]);
			if (i == r && a[i][j] < min)
			{
				min = a[i][j];
			}
		}
		printf("\n");
	}
	printf("%d\n", a[0][m-1]);
	printf("%d\n", min);
	int b[7][7],counter=0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			b[i][j] = -20 + rand() % (20 - (-21));
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	int trans[7][7],sum=0,u,z;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			trans[i][j] = b[j][i];
			printf("%5d ", trans[i][j]);
			if (j==2 && trans[i][j] > 10)
			{
				sum += trans[i][j];
			}
		}
		printf("\n");
	}
	int max = -21;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (trans[i][j] == trans[i][j + 1])
				counter++;
			if (trans[i][j] >= max)
			{
				max = trans[i][j];
				u = i;
				z = j;
			}
		}
	}
	printf("Сумма второго столбца = %d\n", sum);
	printf("Число пар одинаковых соседних элементов: %d\n", counter);
	printf("Координаты максимального (%d;%d)\n",u,z);
	printf("\n\n");
	int students[8][5];
	float sums = 0, grupp = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			students[i][j] = 17 + rand() % (30 - 18);
			printf("%5d ", students[i][j]);
			if (j == 2)
			{
				sums += students[i][j];
				grupp++;
			}
		}
		printf("\n");
	}
	printf("Среднее колво человек %.0f", sums/grupp);
}
