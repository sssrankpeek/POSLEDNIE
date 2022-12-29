#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//_CRT_SECURE_NO_DEPRECATE

struct player {
	char surname[25];
	char position[25];
	char game[25];
};
typedef struct player footballer;

footballer* input_array(footballer* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("\nФутболист %d\n", i + 1);
		printf("Введите фамилию: ");
		scanf("%s", &arr[i].surname);
		printf("Введите позицию: ");
		scanf("%s", &arr[i].position);
		printf("Введите колиество игр: ");
		scanf("%s", &arr[i].game);
	}
	return arr;
}

int print_array(footballer* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("\nФутболист %d\n", i + 1);
		printf(" Фамилия: %s\n", arr[i].surname);
		printf(" Позиция: %s\n", arr[i].position);
		printf(" Игры: %s\n", arr[i].game);
	}
	return 0;
}

int print_one_array(footballer arr, int number) {
	printf("\nФутболист %d\n", number);
	printf(" Фамилия: %s\n", arr.surname);
	printf(" Позиция: %s\n", arr.position);
	printf(" Игры: %s\n", arr.game);
	return 0;
}

int load_footballers(footballer* workers_array_for_file)
{
	char string[256];
	int counter = 0;
	int temp_counter = 0;
	FILE* file;
	file = fopen("futfile.txt", "rt");
	while (!feof(file)) {
		counter++;
		fgets(string, sizeof(string), file);
		char* mini_str = strtok(string, " ");
		while (mini_str != NULL)
		{
			if (temp_counter == 1)
			{
				strcpy(workers_array_for_file[counter - 1].surname, mini_str);
				mini_str = strtok(NULL, " ");
			}
			else if (temp_counter == 2)
			{
				strcpy(workers_array_for_file[counter - 1].position, mini_str);
				mini_str = strtok(NULL, " ");
			}
			else if (temp_counter == 3)
			{
				strcpy(workers_array_for_file[counter - 1].game, mini_str);
				mini_str = strtok(NULL, " ");
			}
			else
			{
				temp_counter = 0;
			}
			temp_counter++;
		}
	}
	return 0;
}

footballer* changeElement(footballer* arr, int elementID)
{
	char surname[25], position[25], game[25];
	printf("\nФутболист %d", elementID);
	printf("\nВведите новую фамилию: ");
	scanf("%s", surname);
	strcpy(arr[elementID - 1].surname, surname);
	printf("Введите новую позицию: ");
	scanf("%s", position);
	strcpy(arr[elementID - 1].position, position);
	printf("Введите новое количество игр: ");
	scanf("%s", game);
	strcpy(arr[elementID - 1].game, game);
	return arr;
}

int finder_element(footballer* arr, int num, char word[25], int size)
{

	for (int i = 0; i < size; i++)
	{
		switch (num)
		{
		case 1:
			if (strcmp(arr[i].surname, word) == 0)
			{
				printf("\nФутболист %d\n", i + 1);
				printf(" Фамилия: %s\n", arr[i].surname);
				printf(" Позиция: %s\n", arr[i].position);
				printf(" Игры: %s\n", arr[i].game);
			}
			break;
		case 2:
			if (strcmp(arr[i].position, word) == 0)
			{
				printf("\nФутболист %d\n", i + 1);
				printf(" Фамилия: %s\n", arr[i].surname);
				printf(" Позиция: %s\n", arr[i].position);
				printf(" Игры: %s\n", arr[i].game);
			}
			break;
		case 3:
			if (strcmp(arr[i].game, word) == 0)
			{
				printf("\nФутболист %d\n", i + 1);
				printf(" Фамилия: %s\n", arr[i].surname);
				printf(" Позиция: %s\n", arr[i].position);
				printf(" Игры: %s\n", arr[i].game);
			}
			break;
		default:
			printf("Ничего не найдено");
		}
	}
	return 0;
}

int sort_elements(footballer* arr, int num, char word[25], int workers_aff_size)
{
	footballer temp_arr[2];
	int counter = 0;
	for (int i = 0; i < workers_aff_size; i++)
	{
		strcpy(temp_arr[i].surname, arr[i].surname);
		strcpy(temp_arr[i].position, arr[i].position);
		strcpy(temp_arr[i].game, arr[i].game);
	}
	for (int i = 0; i < workers_aff_size; i++)
	{
		switch (num)
		{
		case 1:
			if (strcmp(temp_arr[i].surname, word) == 0)
			{
				strcpy(temp_arr[i].surname, arr[i].surname);
				strcpy(temp_arr[i].position, arr[i].position);
				strcpy(temp_arr[i].game, arr[i].game);
				counter++;
			}
			break;
		case 2:
			if (strcmp(temp_arr[i].position, word) == 0)
			{
				strcpy(temp_arr[i].surname, arr[i].surname);
				strcpy(temp_arr[i].position, arr[i].position);
				strcpy(temp_arr[i].game, arr[i].game);
				counter++;
			}
			break;
		case 3:
			if (strcmp(temp_arr[i].game, word) == 0)
			{
				strcpy(temp_arr[i].surname, arr[i].surname);
				strcpy(temp_arr[i].position, arr[i].position);
				strcpy(temp_arr[i].game, arr[i].game);
				counter++;
			}
			break;
		}
	}
	FILE* cou;
	if ((cou = fopen("Counter.txt", "wt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	fprintf(cou, "%d", counter);
	fclose(cou);
}

int write_to_file(footballer* arr, int workers_aff_size)
{
	FILE* out;
	if ((out = fopen("NewFile.txt", "wt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	for (int i = 0; i < workers_aff_size; i++)
	{
		fprintf(out, "%s %s %s \n", arr[i].surname, arr[i].position, arr[i].game);
	}
	return 0;
}

void main()
{
	int count;
	setlocale(LC_ALL, "RUS");
	//1
	footballer footballer_array[20];
	int array_size;
	int number;
	int elementID;
	printf("Введите количество футболистов: ");
	scanf("%d", &array_size);
	input_array(footballer_array, array_size);
	print_array(footballer_array, array_size);
	printf("\nВведите какого футболиста вывести: ");
	scanf("%d", &number);
	print_one_array(footballer_array[number - 1], number);
	puts("\n\nIz fayla");
	//3
	footballer footballer_array_for_file[20];
	int footballer_aff_size = 2;
	load_footballers(footballer_array_for_file);
	print_array(footballer_array_for_file, footballer_aff_size);
	printf("\n\n");
	printf("\nВведите номер элемента массива для изменения: ");
	scanf("%d", &elementID);
	changeElement(footballer_array_for_file, elementID);
	print_array(footballer_array_for_file, footballer_aff_size);
	puts("\n\n");
	int search_number;
	char search_word[25];
	printf("\nВведите номер поля, по которому нужно искать элементы(1 - Фамилия; 2 - Имя; 3 - Отчество; 4 - З/П): ");
	scanf("%d", &search_number);
	printf("\nВведите значение, по которому нужно найти работника: ");
	scanf("%s", &search_word);
	finder_element(footballer_array_for_file, search_number, search_word, footballer_aff_size);
	printf("\n\n");
	sort_elements(footballer_array_for_file, search_number, search_word, footballer_aff_size);
	FILE* cou1;
	if ((cou1 = fopen("Counter.txt", "rt")) == NULL)
	{
		printf("Ошибка открытия файла для записи");
		return 0;
	}
	fscanf(cou1, "%d", &count);
	fclose(cou1);
	print_array(footballer_array_for_file, count);
	write_to_file(footballer_array_for_file, footballer_aff_size);
	return 0;
}
