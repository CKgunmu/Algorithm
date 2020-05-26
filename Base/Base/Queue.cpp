#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

class UnderflowException {};

template<typename T>
class ListNode {
public:
	T value;
	ListNode<T> *next; // ������ ���� nullptr

					   // ������
	ListNode<T>() : next(nullptr) {}
	ListNode<T>(T value1, ListNode<T> *next1) : value(value1), next(next1) {}
};

template<typename T>
class Queue {
public:
	int size;
	ListNode<T> *head, *tail;

	// ������
	Queue<T>() : size(0), head(nullptr), tail(nullptr) {}

	// �Ҹ���
	~Queue<T>() {
		ListNode<T> *t1 = head, *t2;
		while (t1 != nullptr) {
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	// ��� �Լ�
	void push(T value) { // �� �ڿ� �� ���� ����
		// ť�� ��� �־��� ���
		if (size == 0) head = tail = new ListNode<T>(value, nullptr);
		// �� ��
		else {
			tail->next = new ListNode<T>(value, nullptr);
			tail = tail->next;
		}
		size++;
	}

	T front() { // �� ���� ���� ��ȯ
		try {
			// ���� ó��: ť�� ��� ����
			if (size == 0) throw UnderflowException();

			return head->value;
		}
		catch (UnderflowException e) {
			cerr << "ť�� ��� �ִµ� front ������ �õ��߽��ϴ�." << endl;
			exit(1);
		}
	}

	void pop() { // �� ���� ���� ����
		try {
			// ���� ó��: ť�� ��� ����
			if (size == 0) throw UnderflowException();

			ListNode<T> *temp = head;
			head = head->next;
			delete temp;
			if (head == nullptr) tail = nullptr; // ũ�Ⱑ 0�� ��
			size--;
		}
		catch (UnderflowException e) {
			cerr << "ť�� ��� �ִµ� pop ������ �õ��߽��ϴ�." << endl;
			exit(2);
		}
	}
};

template<typename T>
ostream& operator <<(ostream &out, const Queue<T> &LL) { // ���ҵ��� �� �ٿ� ���ʴ�� ���
	ListNode<T> *temp = LL.head;
	out << "front [";
	for (int i = 0; i < LL.size; i++) {
		out << temp->value;
		temp = temp->next;
		if (i < LL.size - 1) out << ", ";
	}
	out << "] rear";
	return out;
}

int main() {
	Queue<int> Q;
	Q.push(0); cout << Q << endl;
	Q.push(1); cout << Q << endl;
	Q.push(2); cout << Q << endl;
	Q.push(3); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.push(4); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.push(5); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	Q.pop(); cout << Q << endl;
	system("pause");
}
