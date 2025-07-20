#include<stdio.h>
#define max 100

char tree[max];

void init(char tree[], int n){
	for(int i = 0; i < n; i++){
		tree[i] = '#';
	}
}

void preorderTraversal(int index){
	if(tree[index] == '#') return;

	printf("%c ", tree[index]);
	preorderTraversal(index * 2 + 1);
	preorderTraversal(index * 2 + 2);
}

int main(){
	// initializing the array with a value
	init(tree, max);

	// building the tree
	tree[0] = 'A';
	tree[1] = 'B';
	tree[2] = 'C';
	tree[5] = 'D';
	tree[6] = 'E';
	tree[3] = 'F';
	tree[4] = 'G';

	preorderTraversal(0);
}