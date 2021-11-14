#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i) //heap형태를 만드는 과정
{ //Find largest among (root, left child, and right child)
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) 
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	//Swap and continue heapifying if root is not largest
	if (largest != i) //왼쪽이나 오른쪽 자식노드 값이 root노드 값보다 큰 경우
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
	/*정렬과정 출력
	if (n != 0)
		printf("%d번째 정렬 과정 : ", n);
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	*/
}
void heapSort(int arr[], int n)
{
	//Build Max Heap
	for (int i = n / 2 - 1; i >=0; i--)
		heapify(arr, n, i);
	
	//Heap Sort
	for (int i = n - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		//Heapify root element to get highest element at root again
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {1, 12, 9, 5, 6, 10, 3, 8, 76};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Before Heap-sort\n");
	printArray(arr, n);
	printf("\n");
	heapSort(arr, n);

	printf("After Heap-sort\n");
	printArray(arr, n);
}