#include <stdio.h>
int main(void) {
	printf("학번: 201951051\n");
	printf("이름: 정동민\n");

	for (int i = 2; i <= 9; i++) {
		printf("%d단: ", i);
		for (int j = 2; j <= 9; j++) {
			printf("%d * %d = %d ", i, j, i*j);
		}
		printf("\n");
	}
}