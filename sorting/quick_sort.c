#include <stdio.h>

void	quick_sort(int arr[], int left, int right)
{
	int pivot;
	int i, j;
	int temp;

	if (left >= right) //원소가 1개인 경우 그대로 두기
		return ;
	pivot = left; //pivot는 첫번째 원소
	i = left + 1;
	j = right;
	while (i <= j) //엇갈릴 때까지 반복
	{
		while (i <= right && arr[i] <= arr[pivot]) //pivot 값보다 큰 값을 만날 때
			i++;
		while (j > left && arr[j] >= arr[pivot]) // pivot 값보다 작은 값을 만날 때
			j--;
		if (i > j) //현재 엇갈린 상태면 pivot 값과 교체
		{
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}

int main()
{
	int i;
	int arr[10] = {5,6,7,3,1,2,9,4,8,0};
	
	quick_sort(arr, 0, 10);
	for (i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}

