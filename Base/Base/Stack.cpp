#include <iostream>
#include <stdlib.h>
#define MAXVALUE 2
using namespace std;

template<class T> class Stack {
public:
	int top;
	int size;
	T *values;
	
	//스택 생성
	Stack() {
		size = MAXVALUE;
		values = new T[size];
		top = -1;
	}
	~Stack() { delete[] values; }

	//스택에 값 추가
	void push(T value) {
		if (!isFull())
			values[++top] = value;
		else
			cout << "Stack is Full" << endl;
	}

	//스택 값 제거
	void pop() {
		if (!empty())
			top--;
		else
			cout << "Stack is Empty" << endl;
	}

	//스택에 제일 나중에 추가된 값 출력
	T Top() {
		if (!empty())
			return values[top];
		else
			return NULL;
	}

	//스택이 비었는지 확인
	bool empty() {
		if (top < 0)
			return true;
		else
			return false;
	}

	//스택의 공간이 다 찼는지 확인
	bool isFull() {
		if (top + 1 == size)
			return true;
		else
			return false;
	}
};

//출력
template<typename T>
ostream& operator <<(ostream &out, Stack<T> &st) {
	T *temp = st.values;
	out << "┌───┐" << endl;
	for (int i = st.top; i >= 0; i--) {
		out << "  " << temp[i] << endl;
	}
	out << "└───┘" << endl;
	return out;
}

int main()
{
	Stack<int> st;
	cout << "Stack push" << endl;
	st.push(1);
	cout << st << endl;
	cout << "Stack push" << endl;
	st.push(3);
	cout << st << endl;
	cout << "Stack push" << endl;
	st.push(5);
	cout << st << endl;
	cout << "Stack Top : " << st.Top() << endl << endl;
	cout << "Stack pop" << endl;
	st.pop();
	cout << st << endl;
	st.pop();
	cout << "Stack pop" << endl;
	cout << st << endl;
	st.pop();
	cout << "Stack pop" << endl;
	cout << st << endl;
	system("pause");
}