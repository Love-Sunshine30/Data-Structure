#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int l, int r){
	int i = l - 1;
	int j;
	int t = arr[r];

	for(j = l; j < r; j++){
		if(arr[j] > t){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	i++;
	swap(&arr[i], &arr[r]);

	return i;

}

void quicksort(int arr[], int l, int r){
	if(l < r){
		int pi = partition(arr, l, r);

		quicksort(arr, l, pi - 1);
		quicksort(arr, pi + 1, r);
	}
}



int main(){
	int arr[] = {4, 9, 7, 8, 2, 9};
	int n = sizeof(arr) / sizeof(arr[0]);

	quicksort(arr, 0,  n - 1);

	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}