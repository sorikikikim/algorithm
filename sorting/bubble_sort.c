#include <stdio.h>

void bubble_sort(int arr[])
{
	int temp, count;

	temp = 0;
	count = 10;
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - 1 - i; j++)
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

int main()
{
	int i;
	int arr[10] = {5,6,7,3,1,2,9,4,8,0};

	bubble_sort(arr);
	for (i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}