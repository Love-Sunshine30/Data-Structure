#include<stdio.h>

int fibs[100] = {-1};

int fibo(int n){
	if(n == 1 || n == 2){
		return 1;
	}
	if(fibs[n] != 0){
		return fibs[n];
	}
	return fibs[n] = fibo(n - 1) + fibo(n - 2);
}
int main(){
	
	int ans = fibo(10);
	printf("%d", ans);
}