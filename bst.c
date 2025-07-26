#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node{
	int data;
	Node *right;
	Node *left;
};
void inorderTraversal(Node* root){
	if(root == NULL) return;

	inorderTraversal(root->left);
	printf("%d ", root->data);
	inorderTraversal(root->right);
}
Node* createNode(int data){
	Node* Newnode = (Node*)malloc(sizeof(Node));
	Newnode->data = data;
	Newnode->left = Newnode->right = NULL;
	return Newnode;
}

Node* insert(Node* root, int value){
	if(root == NULL) return createNode(value);

	if(value <= root->data){
		root->left = insert(root->left, value);
	}
	else{
		root->right = insert(root->right, value);
	}
}
Node* inorderSuccessor(Node* root){
	root = root->right;
	while(root->left != NULL && root != NULL){
		root = root->left;
	}
	return root;
}
Node* delete(Node* root, int value){
	if(root == NULL) return root;

	if(root->data > value){
		root->left = delete(root->left, value);
	}
	else if(root->data < value){
		root->right = delete(root->right, value);
	}

	else{
		if(root->left == NULL){
			Node* temp = root->right;
			free(root);
			return temp;
		}
		if(root->right == NULL){
			Node* temp = root->left;
			free(root);
			return temp;
		}
		Node* succ = inorderSuccessor(root);
		root->data = succ->data;
		root->right = delete(root->right, succ->data);
	}
	return root;
}

int main(){
	Node* root = createNode(7);
	insert(root, 5);
	insert(root, 3);
	insert(root, 2);
	insert(root, 8);
	insert(root, 9);
	insert(root, 2);

	delete(root, 5);
	insert(root, 5);
	inorderTraversal(root);
}