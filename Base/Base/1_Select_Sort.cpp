#include <stdio.h>

/*
	모든 i에 대해 A[i ~ N-1]에서 가장 작은 원소를 찾은 뒤
	이것을 A[i]에 넣는 것
*/

int main(void) {
	int i, j, min, index, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for (i = 0; i < 10; i++)
		printf("%d", array[i]);

	return 0;
} 