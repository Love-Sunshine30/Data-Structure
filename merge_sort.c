#include<stdio.h>

void merge(int a[], int l, int mid, int r){
	int n1 = mid - l + 1;
	int n2 = r - mid;

	int L[n1]; 
	int R[n2];

	for(int i = 0; i < n1; i++){
		L[i] = a[l + i];
	}

	for(int i = 0; i < n2; i++){
		R[i] = a[mid + i + 1];
	}

	int k = l, i = 0, j = 0;

	while(i < n1 && j < n2){
		if(L[i] >= R[j]){
			a[k++] = L[i++];
		}
		else{
			a[k++] = R[j++];
		}
	}

	while(i < n1){
		a[k++] = L[i++];
	}
	while(j < n2){
		a[k++] = R[j++];
	}
}

void mergesort(int a[], int l, int r){
	int mid = l + (r - l) / 2;

	if(l < r){
	mergesort(a, l, mid);
	mergesort(a, mid + 1, r);

	merge(a, l, mid, r);
	}

	// merge(a, l, mid, r);
}

int main(){
	int n; scanf("%d", &n);

	int arr[n];

	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	mergesort(arr, 0, n - 1);

	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}