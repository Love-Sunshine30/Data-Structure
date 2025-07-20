#include<stdio.h>

typedef struct{
	int data;
	Node *right;
	Node *left;
}Node;

Node* createNode(int data){
	Node *Newnode = (*Node)malloc(sizeof(Node));
	Newnode->data = data;
	Newnode->left = Newnode->right = NULL;
	return Newnode;
}

Node* insert(Node* root, int value){
	if(root == NULL) return createNode(value);

	if(value < root->data){
		root->left = insert(root->left, value);
	}
	else{
		root->left = insert(root->right, value);
	}
}


int main(){
	Node *root = createNode(1);
}