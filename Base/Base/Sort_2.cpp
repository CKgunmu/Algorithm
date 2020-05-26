#include <stdio.h>

int main(void) {
	int n[1002] = {};
	int temp, index, min, i, j, X;
	
	scanf("%d", &X);

	for (i = 0; i < X; i++) {
		scanf("%d", &n[i]);
	}

	for (i = 0; i < X; i++) {
		min = 100000000;
		for (j = i; j < X; j++) {
			if (min > n[j]) {
				min = n[j];
				index = j;
			}
		}
		temp = n[i];
		n[i] = n[index];
		n[index] = temp;
	}

	for (int i = 0; i < X; i++)
		printf("%d\n", n[i]);
}