#include <stdio.h>

int main(void) {
	int n[3] = {};
	int temp, index, min, i, j;
	scanf("%d %d %d", &n[0], &n[1], &n[2]);

	for (i = 0; i < 3; i++) {
		min = 100000000;
		for (j = i; j < 3; j++) {
			if (min > n[j]) {
				min = n[j];
				index = j;
			}
		}
		temp = n[i];
		n[i] = n[index];
		n[index] = temp;
	}

	for (int i = 0; i < 3; i++)
		printf("%d ", n[i]);
}