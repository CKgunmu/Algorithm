#include <stdio.h>
int main(void) {
	printf("�й�: 201951051\n");
	printf("�̸�: ������\n");

	for (int i = 2; i <= 9; i++) {
		printf("%d��: ", i);
		for (int j = 2; j <= 9; j++) {
			printf("%d * %d = %d ", i, j, i*j);
		}
		printf("\n");
	}
}