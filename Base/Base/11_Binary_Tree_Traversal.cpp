#include <iostream>
using namespace std;

int number = 15;
typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftchild, rightChild;
}node;

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftchild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftchild);
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftchild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void) {
	node nodes[16];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftchild = NULL;
		nodes[i].rightChild = NULL;
	}

	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) nodes[i / 2].leftchild = &nodes[i];
		else nodes[i / 2].rightChild = &nodes[i];
	}

	preorder(&nodes[1]);
}