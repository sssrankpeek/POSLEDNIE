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
		printf("������ �������� ����� ��� ������");
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		printf("\n������� ������� ������: ");
		scanf(" %s", A.surname);
		printf("\n������� ���� �������� ������: ");
		scanf(" %d%d%d", &A.day, &A.month, &A.year);
		printf("\n������� ����� �������� ������: ");
		scanf(" %s", A.place);
		printf("\n������� ������� ������: ");
		scanf(" %s", A.position);
		printf("\n������� ��������� ���������� ���: ");
		scanf(" %f", &A.game);
		printf("\n������� ���������� ���������� ����� ����: ");
		scanf(" %d", &A.ycard);
		fprintf(ot, "�������: %s, ���� ��������: %d.%d.%d, ����� ��������: %s, �������: %s, ����: %f, ��������: %d\n", A.surname, A.day, A.month, A.year, A.place, A.position, A.game, A.ycard);
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
	puts("�������� �����");
	if ((out = fopen(fname, "wt")) == NULL)
	{
		printf("������ �������� ����� ��� ������");
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
	printf("\n������� ��� ��������� �������:");
	scanf("%f", &tabu);
	printf("\n��� ������ ����������� � ������ ���� ������� 1, ��� ������ � ����� ������� 2");
	scanf("%d",&q);
	switch (q)
	{
	case 1:
		out = fopen(fname, "a");
		if ((out = fopen(fname, "a")) == NULL)
		{
			printf("������ �������� ����� ��� ������");
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
		puts("�������� �����");
		if ((tab = fopen(fname2, "wt")) == NULL)
		{
			printf("������ �������� ����� ��� ������");
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
