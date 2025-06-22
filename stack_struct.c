#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* top = NULL;
void push(int value){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode-> next = top;
	top = newNode;
}
// Akbar did this part
int pop(){
	if(top==NULL){
		return -999;
	}
	else{
	    int temp = top->data;
	    top = top->next;
	    return temp;
	}
}
// Akbar did this part
void display(){
	if(top==NULL){
		printf("Stack is Empty!");
	}
	else{
		while(top!=NULL){
			printf("%d ",top->data);
			top = top->next;
		}
	}
}

int peek(){
	if(top == NULL){
		printf("Nothing to peek\n");
		return -999;
	}
	else{
		return top->data;
	}
}
int main(){
	push(3);
	push(6);
	push(9);

	// printf("%d ",pop());
	//display();
	pop();
	printf("%d",peek());

}
