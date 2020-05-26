#include <stdio.h>
struct BinaryTreeNode {
	int data;
	int left;
	int right;
};

// 1 2 4 8 9 5 10 11 3 6 12 13 7 14 15
void PreOrder(struct BinaryTreeNode *root) {
	if (root) {
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

// 8 4 9 2 10 5 11 1 12 6 13 3 14 7 15
void InOrder(struct BinaryTreeNode *root) {
	if (root) {
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

// 8 9 4 10 11 5 2 12 13 6 14 15 7 3 1
void Postorder(struct BinaryTreeNode *root) {
	if (root) {
		Postorder(root->left);
		Postorder(root->right);
		printf("%d ", root->data);
	}
}