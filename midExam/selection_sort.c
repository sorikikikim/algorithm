#include <stdio.h>
#define size 20

void	selection_sort(double arr[])
{
	double temp;
	int min_index;

	for (int i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (int j = i; j < size; j++)
			if (arr[j] < arr[min_index])
				min_index = j;
		temp = arr[min_index];
		arr[min_index] = arr[i];
		arr[i] = temp; 
	}
}

int main()
{
	double input[20] = {4, 12, 9, 5, 2, 17, 8, 3, 16, 11, 18, 0, 1, 15, 7, 13, 19, 6, 10, 14};

	printf("정렬 전 실수 20개 >> ");
	for (int i = 0; i < size; i++)
		printf("%.1lf ", input[i]);
	printf("\n");

	selection_sort(input);
	printf("선택 정렬 결과	  >> ");
	for (int i = 0; i < size; i++)
		printf("%.1lf ", input[i]);
	printf("\n");
}

