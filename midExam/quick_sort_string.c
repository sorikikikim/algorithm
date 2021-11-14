#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 500

void swap(char (*arr)[MAX_NUM], int a, int b) // a,b 스왑 함수 
{
	if (a == b)
		return ; 
	char temp[MAX_NUM];
	strcpy(temp, arr[a]);
	strcpy(arr[a], arr[b]);
	strcpy(arr[b], temp);
}

int partition(char (*arr)[MAX_NUM], int left, int right)
{
    char *pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
    int low = left + 1;
    int high = right;
 
    while (low <= high) // 교차되기 전까지 반복한다 
    {
        while (low <= right && strcmp(pivot, arr[low]) >= 0) // 피벗보다 큰 값을 찾는 과정 
            low++; // low를 오른쪽으로 이동 
        while (high >= (left+1)  && strcmp(pivot, arr[high]) <= 0) // 피벗보다 작은 값을 찾는 과정 
            high--; // high를 왼쪽으로 이동
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
            swap(arr, low, high); //low와 high를 스왑 
    }
    swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환 
    return high;  // 옮겨진 피벗의 위치정보를 반환 
}
 

void quickSort(char (*arr)[MAX_NUM], int left, int right)
{
    if (left <= right)
    {
        int pivot = partition(arr, left, right); // 둘로 나누어서
        quickSort(arr, left, pivot - 1); // 왼쪽 영역을 정렬한다.
        quickSort(arr, pivot + 1, right); // 오른쪽 영역을 정렬한다.
    }
}
 
//메인함수
int main()
{
	FILE *fptr;

    int i, n;
	char arr[20][MAX_NUM];
	int count = 0;

	fptr = fopen("string_data.txt", "r");
	if (fptr == NULL){
		printf("문자열 데이터 파일 열기 실패\n");
		return 0;
	}

	while (!feof(fptr)) {
		fgets(arr[count], MAX_NUM, fptr);
		count++;
	}
	arr[count - 1][strlen(arr[count - 1])] = '\n';
	arr[count - 1][strlen(arr[count - 1]) + 1] = '\0';

	printf("Quick sort 전 배열 : \n");
	for(i = 0 ; i < count ; i++)
       printf("%s", arr[i]);
	printf("\n");

    quickSort(arr, 0, count - 1);

	printf("Quick sort 후 배열 : \n");
    for(i = 0 ; i < count; i++)
    	printf("%s", arr[i]);
	printf("\n");

    return 0;
}