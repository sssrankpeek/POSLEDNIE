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
		printf("\n��������� %d\n", i + 1);
		printf("������� �������: ");
		scanf("%s", &arr[i].surname);
		printf("������� �������: ");
		scanf("%s", &arr[i].position);
		printf("������� ��������� ���: ");
		scanf("%s", &arr[i].game);
	}
	return arr;
}

int print_array(footballer* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("\n��������� %d\n", i + 1);
		printf(" �������: %s\n", arr[i].surname);
		printf(" �������: %s\n", arr[i].position);
		printf(" ����: %s\n", arr[i].game);
	}
	return 0;
}

int print_one_array(footballer arr, int number) {
	printf("\n��������� %d\n", number);
	printf(" �������: %s\n", arr.surname);
	printf(" �������: %s\n", arr.position);
	printf(" ����: %s\n", arr.game);
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
	printf("\n��������� %d", elementID);
	printf("\n������� ����� �������: ");
	scanf("%s", surname);
	strcpy(arr[elementID - 1].surname, surname);
	printf("������� ����� �������: ");
	scanf("%s", position);
	strcpy(arr[elementID - 1].position, position);
	printf("������� ����� ���������� ���: ");
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
				printf("\n��������� %d\n", i + 1);
				printf(" �������: %s\n", arr[i].surname);
				printf(" �������: %s\n", arr[i].position);
				printf(" ����: %s\n", arr[i].game);
			}
			break;
		case 2:
			if (strcmp(arr[i].position, word) == 0)
			{
				printf("\n��������� %d\n", i + 1);
				printf(" �������: %s\n", arr[i].surname);
				printf(" �������: %s\n", arr[i].position);
				printf(" ����: %s\n", arr[i].game);
			}
			break;
		case 3:
			if (strcmp(arr[i].game, word) == 0)
			{
				printf("\n��������� %d\n", i + 1);
				printf(" �������: %s\n", arr[i].surname);
				printf(" �������: %s\n", arr[i].position);
				printf(" ����: %s\n", arr[i].game);
			}
			break;
		default:
			printf("������ �� �������");
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
		printf("������ �������� ����� ��� ������");
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
		printf("������ �������� ����� ��� ������");
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
	printf("������� ���������� �����������: ");
	scanf("%d", &array_size);
	input_array(footballer_array, array_size);
	print_array(footballer_array, array_size);
	printf("\n������� ������ ���������� �������: ");
	scanf("%d", &number);
	print_one_array(footballer_array[number - 1], number);
	puts("\n\nIz fayla");
	//3
	footballer footballer_array_for_file[20];
	int footballer_aff_size = 2;
	load_footballers(footballer_array_for_file);
	print_array(footballer_array_for_file, footballer_aff_size);
	printf("\n\n");
	printf("\n������� ����� �������� ������� ��� ���������: ");
	scanf("%d", &elementID);
	changeElement(footballer_array_for_file, elementID);
	print_array(footballer_array_for_file, footballer_aff_size);
	puts("\n\n");
	int search_number;
	char search_word[25];
	printf("\n������� ����� ����, �� �������� ����� ������ ��������(1 - �������; 2 - ���; 3 - ��������; 4 - �/�): ");
	scanf("%d", &search_number);
	printf("\n������� ��������, �� �������� ����� ����� ���������: ");
	scanf("%s", &search_word);
	finder_element(footballer_array_for_file, search_number, search_word, footballer_aff_size);
	printf("\n\n");
	sort_elements(footballer_array_for_file, search_number, search_word, footballer_aff_size);
	FILE* cou1;
	if ((cou1 = fopen("Counter.txt", "rt")) == NULL)
	{
		printf("������ �������� ����� ��� ������");
		return 0;
	}
	fscanf(cou1, "%d", &count);
	fclose(cou1);
	print_array(footballer_array_for_file, count);
	write_to_file(footballer_array_for_file, footballer_aff_size);
	return 0;
}
