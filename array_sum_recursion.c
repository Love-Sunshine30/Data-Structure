#include<stdio.h>
#define N  10

int arr[] = {1, 2, 8, 4, 9, 5, 2, 4, 8, 9};

int sum(int i){
	if(i == N - 1){
		return arr[i];
	}
	return arr[i] + sum(i + 1);
}

int main(){
	int ans = sum(0);
	printf("%d", ans);

}