#include <stdio.h>
#define SIZE 20

int getMax(int arr[], int n){
	int max = arr[0];
	int i;

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void countingSort(int arr[], int n, int exp){ 
	int output[SIZE];
	int i;
	int count[10] = {0};

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--){
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
} 

void radixSort(int arr[], int n){ 
	int max = getMax(arr, n);
	int exp;


	printf("3. 매 단계 출력 : \n");
	for (exp = 1; max / exp > 0; exp *= 10){
		countingSort(arr, n, exp);
		printf("%d의 자리 정렬 - \n", exp); 
		for (int i = 0; i < n; i++)
			printf ("%d   ", arr[i]);
		printf("\n");
	}
}

int main() {
	int i;
	int arr[SIZE];
	int count = 0;
	int n = sizeof(arr) / sizeof(arr[0]);

	FILE *rp;
	rp = fopen("DataInt5.txt", "r");
	if (rp == NULL){
		printf("fopen error\n");
		return 0;
	}

	printf("2. Before radix sort : ");
	while (!feof(rp)){
		fscanf(rp, "%d", &arr[count]);
		printf("%d ", arr[count]);
		count++;
	}
	printf("\n");

	radixSort(arr, n);

	printf("4. After radix sort : ");
	for (i = 0; i < n; i++)
		printf("%d	", arr[i]);
	printf("\n");

	printf("5. 학과 학번 이름 : 컴퓨터공학과 1891021 김소리\n");
}