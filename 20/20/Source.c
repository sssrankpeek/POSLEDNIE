#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<io.h>
void main()
{
	setlocale(LC_ALL,"RUS");
	float sum = 0, a,n=0,kvadrat;
	FILE *f;
	f = fopen("temp.txt","r");
	while (!feof(f))
	{
		fscanf(f, "%f\n", &a);
		sum += a;
		n++;
	}
	fclose(f);
	printf("sr arifm=%f", sum/n);
	srand(time(NULL));
	FILE* cifri;
	char name[20] = "cifri.txt";
	cifri = fopen("cifri.txt","w");
	if ((cifri = fopen(name, "wt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	for (int i = 0; i < 5; i++)
	{
		float y;
		y = 0.1 + 1.f * (9.9 - 0.1) * rand() / RAND_MAX;
		fprintf(cifri,"%f\n",y);
	}
	fclose(cifri);
	fopen("cifri.txt", "r");
	if ((cifri = fopen(name, "r")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	FILE* cifrikvadrat;
	char name2[20] = "cifrikvadrat.txt";
	cifrikvadrat = fopen("cifrikvadrat.txt","w");
	while (!feof(cifri))
	{
		fscanf(cifri, "%f\n", &a);
		kvadrat = a * a;
		fprintf(cifrikvadrat,"%.2f\n",kvadrat);
	}
	fclose(cifri);
	fclose(cifrikvadrat);
}