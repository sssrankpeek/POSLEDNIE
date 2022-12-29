#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
double* randmassiv(int n, double* ptr_array)
{
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] = -10 + 1.f * (20 - -10) * rand() / RAND_MAX;
	}
	for (int i = 0; i < n; i++)
	{
		printf("\nptr_array[%d] = %.3lf", i, ptr_array[i]);
	}
	return ptr_array;
}
double sum_elements(int n, double* array3)
{
	double sum=0;
	for (int i = 0; i < n; i++)
	{
		sum += array3[i];
	}
	return sum;
}
double* reverse(int n, double* array2, double* arrayres)
{
	int i;
	for (i = n-1; i >= 0; i--)
	{
		arrayres[n-1-i] = array2[i];
	}
	return arrayres;
}
double* obiedin(double* arr4, int size4, double* arr1,int size1, double* arr2,int size2, double arr3) 
{
	int counter=0;
	for (int i = 0; i < size1; i++)
	{
		arr4[i] = arr1[i];
		counter++;
	}
	for (int i = counter; i < counter + size2; i++)
	{
		arr4[i] = arr2[i - counter];
	}
	arr4[counter + size2] = arr3;
	for (int i = 0; i < size4; i++)
	{
		printf("\narr4[%d] = %.3lf", i, arr4[i]);
	}
	return arr4;
} 
void main()
{
	setlocale(LC_ALL,"RUS");
	srand(time(NULL));
	int size1 = 5 + rand() % 10 - 5+1;
	int size2 = 5 + rand() % 10 - 5+1;
	int size3 = 5 + rand() % 10 - 5+1;
	int size4 = size1 + size2 + 1;
	double* arr1 = (double*)malloc(size1 * sizeof(double));
	double* arr2 = (double*)malloc(size2 * sizeof(double));
	double* arr2res = (double*)malloc(size2 * sizeof(double));
	double* arr3 = (double*)malloc(size3 * sizeof(double));
	double* arr4 = (double*)malloc(size4 * sizeof(double));
	randmassiv(size1,arr1);
	printf("\n\n");
	randmassiv(size2, arr2);
	printf("\n\n");
	randmassiv(size3, arr3);
	printf("\nСумма элементов третьего массива = %lf", sum_elements(size3,arr3));
	printf("\n\n");
	reverse(size2, arr2,arr2res);
	for (int i = 0; i < size2; i++)
	{
		printf("\narr2res[%d] = %.3lf", i,arr2res[i]);
	}
	printf("\n\n");
	obiedin(arr4,size4,arr1,size1,arr2res,size2,sum_elements(size3,arr3));
}
