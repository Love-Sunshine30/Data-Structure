#include<stdio.h>
#define N 100

int heap[N];
int n;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int heap[], int i, int n){
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && heap[left] > heap[largest]){
		largest = left;
	}

	if(right < n && heap[right] > heap[largest]){
		largest = right;
	}
	if(i != largest){
		swap(&heap[i], &heap[largest]);
		max_heapify(heap, largest, n);
	}

}

void build_heap(int heap[], int n){
	for(int i = n / 2; i >= 0; i--){
		max_heapify(heap, i, n);
	}
}

int extract_max(int heap[]){
	if(n == -1){
		printf("The heap is empty!");
		return -1;
	}
	int max = heap[0];
	heap[0] = heap[n - 1];
	n--;
	max_heapify(heap, 0, n);
	return max;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &heap[i]);
	}

	build_heap(heap, n);

	for(int i = 0; i < n; i++){
		printf("%d ", extract_max(heap));
	}
	for(int i = 0; i < n; i++){
		printf("%d ", heap[i]);
	}
}