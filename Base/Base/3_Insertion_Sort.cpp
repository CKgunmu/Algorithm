#include <stdio.h>

/*
	전체 배열 중 정렬되어 있는 부분배열에 새 원소를 끼워 넣는 일을 
	반복하는 방식으로 동작
*/

int main(void) {
	int i, j, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 9; i++) {
		j = 1;
		while (j >= 0 && array[i] > array[j + 1]) { 
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}

	for (i = 0; i < 10; i++)
		printf("%d", array[i]);
	
} 