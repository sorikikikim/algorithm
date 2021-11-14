#include <stdio.h>

#define SIZE 100

int getMax(int arr[], int n){
	int max = arr[0];
	int i;

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void countingSort(int arr[], int n, int exp){ //한자리내에서 정렬할때
//배열 내에 원소 값들의 개수를 저장하는 배열
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

void radixSort(int arr[], int n){ //자리수까지 고려해서 정렬
	int max = getMax(arr, n);
	int exp; //자리수

	for (exp = 1; max / exp > 0; exp *= 10)
		countingSort(arr, n, exp);
}

int main() {
	int arr[] = {170, 745, 375, 990, 802, 224, 432, 666};
	int n = sizeof(arr) / sizeof(arr[0]);
	radixSort(arr, n);
	//countingSort(arr, n , 100);
	int i = 0;
	while (i < n){
		printf("%d\n", arr[i]);
		i++;
	}
}

/*
#include<stdio.h>
#include<queue>
using namespace std;
 
int get_max_radix(int *arr, int size){
	
	int max_val = 0;
	for(int i = 0 ; i < size ; i++){
		if(max_val < arr[i]){
			max_val = arr[i];
		}
	}
	
	int max_radix = 1;
	while(max_val / 10 > 0){
		max_val /= 10;
		max_radix *= 10;
	}
	
	return max_radix;
}
 
void radix_sort(int *arr, int size){
	int max_radix = get_max_radix(arr, size);
	
	queue<int> Q[10]; // Queue 10개 (1 ~ 9 자리)
	
	for(int i = 1 ; i <= max_radix ; i *= 10){
		for(int j = 0 ; j < size ; j++){
	
			int k = 0; 
			// 자리수 
					
			if(arr[j] >= i){ 
				k = (arr[j] / i) % 10;
				// (1, 10, 100)보다 크면 계산하고 
				// 작으면 0으로 처리함 
				// (e.g. 10의자리에서 2 -> 02 -> 0) 
			}
			
			Q[k].push(arr[j]);
		}
		
		int idx = 0;
		for(int j = 0 ; j < 10 ; j++){
			
			while(!Q[j].empty()){ 
				arr[idx] = Q[j].front();
				Q[j].pop();
				idx++;
			}
		}
	} 
}
 
int main(){
	
	int arr[] = {1,3,2,4,1,23,126,213,12,12,3,12,3,23,23};	
	int size = sizeof(arr)/sizeof(arr[0]);
	radix_sort(arr, size);
	
	for(int i = 0 ; i < size ; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}*/