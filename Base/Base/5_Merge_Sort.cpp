#include <stdio.h>
int number = 8;
int sorted[8]; // 배열은 반드시 정렬되어 있어야함

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;

	//작은 순서대로 삽입
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t < n; t++) {
			sorted[k] = a[t];
			i++;
		}
	} else {
		for (int t = i; t <= middle; t++)
			sorted[k] = a[t];
		k++;
	}

	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
	

}

void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {
	int array[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, 7);
	for (int i = 0; i < 8; i++) {
		printf("%d ", array[i]);
	}
}