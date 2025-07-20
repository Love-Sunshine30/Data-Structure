#include<stdio.h>
#include<stdlib.h>

// defining a node
typedef struct Node Node;
struct Node{
	char data;
	Node* left;
	Node* right;
};

// creates a node
Node* createNode(char value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->left = newNode-> right = NULL;
}

// preorder traversal
void preorderTraversal(Node* root){
	if(root == NULL) return;

	printf("%c ", root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void inorderTraversal(Node* root){
	if(root == NULL) return;

	inorderTraversal(root->left);
	printf("%c ", root->data);
	inorderTraversal(root->right);
}

void postorderTraversal(Node* root){
	if(root == NULL) return;

	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%c ", root->data);
}
int main(){
	// creating the nodes
	Node* root = createNode('A');
	Node* nodeB = createNode('B');
	Node* nodeC = createNode('C');
	Node* nodeD = createNode('D');
	Node* nodeE = createNode('E');

	// Linking the nodes
	root->left = nodeB;
	root->right = nodeC;
	nodeC->left = nodeD;
	nodeC->right = nodeE;

	//preorderTraversal(root);
	//inorderTraversal(root);
	//postorderTraversal(root);
}