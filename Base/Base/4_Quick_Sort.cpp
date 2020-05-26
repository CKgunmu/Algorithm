#include <stdio.h>

/*
	�ϳ��� ������ �ΰ��� ���� ������ �����ϴ� ������� ������ ����
	�����Ŀ����� ���ذ��� �ִµ� �̸� �ǹ��̶�� �մϴ�.
	���� �ǹ����� ù��° ���Ҹ� �ǹ� ������ ���
*/

int number = 10;
int data[] = { 1,10,5,8,7,6,4,3,2,9 };

void show() {
	int i;
	for (i = 0; i < number; i++)
		printf("%d", data[i]);
}

void quickSort(int* data, int start, int end) {
	if (start >= end)			// ���Ұ� 1���� ���
		return;

	int key = start;			// key�� ù��° ����
	int i = start + 1, j = end, temp;

	while (i <= j) {			//������ �� ���� �ݺ�
		while (i <= end && data[i] <= data[key]) i++; //key������ Ŭ��
		while (j > start && data[j] >= data[key]) j--;//key������ ������
	
		if (i > j) {			// ������ �����϶� key�� ��ü
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {					// �������� �ʾҴٸ� i,j��ü
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1); // ���� 1�� ����.
	quickSort(data, j + 1, end);   // ���� �� 1�� ����
}

int main(void) {
	quickSort(data, 0, number - 1);
	show();
	return 0;
}