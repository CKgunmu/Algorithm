#include <stdio.h>

/*
	하나의 문제를 두개의 작은 문제로 분할하는 방식으로 빠르게 정렬
	퀵정렬에서는 기준값이 있는데 이를 피벗이라고 합니다.
	보통 피벗값은 첫번째 원소를 피벗 값으로 사용
*/

int number = 10;
int data[] = { 1,10,5,8,7,6,4,3,2,9 };

void show() {
	int i;
	for (i = 0; i < number; i++)
		printf("%d", data[i]);
}

void quickSort(int* data, int start, int end) {
	if (start >= end)			// 원소가 1개인 경우
		return;

	int key = start;			// key는 첫번째 원소
	int i = start + 1, j = end, temp;

	while (i <= j) {			//엇갈릴 때 까지 반복
		while (i <= end && data[i] <= data[key]) i++; //key값보다 클때
		while (j > start && data[j] >= data[key]) j--;//key값보다 작을때
	
		if (i > j) {			// 엇갈린 상태일때 key값 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {					// 엇갈리지 않았다면 i,j교체
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1); // 끝값 1개 줄임.
	quickSort(data, j + 1, end);   // 시작 값 1개 줄임
}

int main(void) {
	quickSort(data, 0, number - 1);
	show();
	return 0;
}