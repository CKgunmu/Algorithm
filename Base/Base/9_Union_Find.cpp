#include <stdio.h>
int getparent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getparent(parent, parent[x]);
}

void unionparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a < b) parent[a] = b;
	else parent[a] = b;
}

int findparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int main(void) {
	int parent[11];
	for (int i = 1; i <= 10; i++)
		parent[i] = i;

	unionparent(parent, 1, 2);
	unionparent(parent, 2, 3);
	unionparent(parent, 3, 4);
	unionparent(parent, 5, 6);
	unionparent(parent, 6, 7);
	unionparent(parent, 7, 8);
	printf("1�� 5�� ����Ǿ��ֳ���? %d\n", findparent(parent, 1, 5));
	unionparent(parent, 1, 5);
	printf("1�� 5�� ����Ǿ��ֳ���? %d\n", findparent(parent, 1, 5));
}

