#include <stdio.h>
#define size 20

void bubble_sort(double arr[])
{
	double temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	double input[size] = {4, 12, 9, 5, 2, 17, 8, 3, 16, 11, 18, 0, 1, 15, 7, 13, 19, 6, 10, 14};

	printf("정렬 전 실수 20개 >> ");
	for (int i = 0; i < size; i++)
		printf("%.1lf ", input[i]);
	printf("\n");

	bubble_sort(input);
	printf("버블 정렬 결과	  >> ");
	for (int i = 0; i < size; i++)
		printf("%.1lf ", input[i]);
	printf("\n");
}

