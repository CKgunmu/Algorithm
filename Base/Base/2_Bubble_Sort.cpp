#include <stdio.h>

/*
	���� �ִ� ���� ���Ͽ� �� ���� ���� �ݺ������� ������ ������ ���� ���
*/

int main(void) {
	int i, j, temp;
	int sort[10] = { 1, 10 ,5, 8, 7, 6, 4, 3, 2, 9 };
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (sort[j] > sort[j + 1]) {
				temp = sort[j];
				sort[j] = sort[j + 1];
				sort[j + 1] = temp;
			}
		}
	}

	for (i = 0; i < 10; i++)
		printf("%d ", sort[i]);

	printf("\n\n");
}