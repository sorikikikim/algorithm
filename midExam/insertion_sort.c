#include <stdio.h>
#define size 20

void insertion_sort(double arr[])
{
    double key;
	int i, j;
 
    for (i = 1; i < size; i++)
	{
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
				arr[j+1] = arr[j]; 
        arr[j + 1] = key;
    }
}

int main()
{
	double input[20] = {4, 12, 9, 5, 2, 17, 8, 3, 16, 11, 18, 0, 1, 15, 7, 13, 19, 6, 10, 14};

	printf("정렬 전 실수 20개 >> ");
	for (int i = 0; i < size; i++)
		printf("%.1lf ", input[i]);
	printf("\n");

	insertion_sort(input);
	printf("삽입 정렬 결과	  >> ");
	for (int i = 0; i < size; i++)
		printf("%.1lf ", input[i]);
	printf("\n");
}

