#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

void	merge(int arr[], int left, int right)
{
	int l, r, i, j;
	int mid;
	int temp[right - left + 1];

	mid = (left + right) / 2;
	l = left;
	r = mid + 1;
	j = 0;
	while (l <= mid && r <= right)
	{
		if (arr[l] <= arr[r])
			temp[j++] = arr[l++];
		else
			temp[j++] = arr[r++];
	}
	if (l > mid)
	{
		for (i = r; i <= right; i++)
			temp[j++] = arr[i];
	}
	else
	{
		for (i = l; i <= mid; i++)
			temp[j++] = arr[i];
	}
	for (i = left; i <= right; i++)
		arr[i] = temp[i - left];
}

void	merge_sort(int arr[], int left, int right)
{
	int mid;

	if (left == right)
		return ;
	mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, right);
}

int main()
{
	int i;
	char temp[80];
	int arr[MAX_SIZE];
	int count = 0;

	//int arr[10] = {5,6,7,3,1,2,9,4,8,0};
	FILE *rp;
	rp = fopen("int_data.txt", "r");
	if (rp == NULL){
		printf("fopen error\n");
		return 0;
	}

	while (!feof(rp)){
		fscanf(rp, "%d", &arr[count]);
		count++;
	}

	merge_sort(arr, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}