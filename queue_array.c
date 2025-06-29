#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int queue[MAX];
int front = -1, back = -1;

void enqueue(int value){
	if(front == back && front == -1){
		front = back = 0;
		queue[back] = value;
		return;
	}
	if(back + 1 % MAX == front){
		printf("The queue is full.");
		return;
	}
	back = back + 1 % MAX;
	queue[back] = value;
}

void dequeue(){
	if(front == back && front == -1){
		printf("The queue is empty.");
		return;
	}
	if(front == -1){
		front = back = -1;
	}else{
		front = front + 1 % MAX;
	}
}


int main(){
	enqueue(1);
	enqueue(8);
	enqueue(7);
	//enqueue(6);
	dequeue();
	dequeue();
	dequeue();
	
	enqueue(5);
	enqueue(4);
	enqueue(5);
	enqueue(4);
	//enqueue(9);
	//peek();
	//peek();
}