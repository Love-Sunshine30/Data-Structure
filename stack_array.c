#include<stdio.h>
#define MAX 105 // Max stack size

int stack[MAX];
int top = -1;

//push() would insert an element to the stack
void push(int value){
	if(top == MAX - 1){
		printf("Stack overflow! Cannot push %d", value);
	}else{
		top++;
		stack[top] = value;
	}
}

// pop() will pop the top element from the stack 
int pop(){
	if(top == -1){
		printf("Stack is empty. Returns 9999");
		return 9999;
	}else{
		int temp = stack[top];
		top--;
		return temp;
	}

}

// peek() will return the top element of the stack
int peek(){
	if(top == -1){
		printf("Stack is empty. Returns 9999");
		return 9999;
	}else{
		return stack[top];
	}
}

void display(){
	if(top == -1){
		printf("Stack is empty. Nothing to display");
	}else{
		for(int i = top; i >= 0; i--){
			printf("%d ", stack[i]);
		}
	}
}

int main(){
	push(1);
	push(4);
	push(5);

	display();

	printf("%d", pop());
}