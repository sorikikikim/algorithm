#include <stdio.h>

void selection_sort(int arr[], int count)
{
	int index_min;
	int i, j;
	int temp;

	index_min = 0;
	//오름차순 (작은 수 -> 큰 수)
	for (i = 0; i < count - 1; i++)
	{
		index_min = i;
		for (int j = i + 1; j < count; j++)
		{
			if (arr[j] < arr[index_min])
				index_min = j;
			//data[indexMin]을 기준으로 data[j]를 검사한다.
             //data[indexMin]의 값 보다 작은 값을 발견시 indexMin = j가 된다.
		}
	//내부 for문의 반복으로 가장 작은 값을 찾으면 순서를 바꾼다.
	temp = arr[index_min];
	arr[index_min] = arr[i];
	arr[i] = temp;
	}
	
}

int main()
{
	int arr[10] = {5,6,7,3,1,2,9,4,8,0};
	int i;

	selection_sort(arr, 10);
	for (i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}

