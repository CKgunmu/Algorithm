#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

class MyString {
	char* string_content;  // 문자열 데이터를 가리키는 포인터
	int string_length;     // 문자열 길이
	int memory_capacity;   // 현재 할당된 용량

public:
	MyString(char c);					// 문자 하나로 생성
	MyString(const char* str);			// 문자열로 부터 생성
	MyString(const MyString& str);		// 복사 생성자
	~MyString();						// 동적할당해제

	MyString& assign(const char* str);	// 문자열로 부터 생성
	MyString& assign(const MyString& str); // 복사 생성자
	
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	MyString& erase(int loc, int num);

	int length() const;					// 문자열 계수 출력
	int capacity() const;				// 용량출력
	int find(int find_from, const MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;
	int compare(const MyString& str) const;

	char at(int i) const;				// 문자열 위치

	void reserve(int size);				// 메모리 할당 
	void print() const;					// 출력
	void println() const;				// 출력 후 개행
};

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
		string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
	if (str.string_length > string_length) {
		delete[] string_content;
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
	string_length = str.string_length;
	return *this;
}

MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > string_length) {
		delete[] string_content;
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}
	string_length = str_length;
	return *this;
}

int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++) {
			string_content[i] = prev_string_content[i];
		}
		delete[] prev_string_content;
	}
}

char MyString::at(int i) const { 
	if (i >= string_length || i < 0)
		return NULL;
	else
		return string_content[i];
}
MyString& MyString::insert(int loc, const MyString& str) {
	// 이는 i 의 위치 바로 앞에 문자를 삽입하게 된다. 예를 들어서
	// abc 라는 문자열에 insert(1, "d") 를 하게 된다면 adbc 가 된다.

	// 범위를 벗어나는 입력에 대해서는 삽입을 수행하지 않는다.
	if (loc < 0 || loc > string_length) {
		return *this;
	}

	if (string_length + str.string_length > memory_capacity) {
		// 이제 새롭게 동적으로 할당을 해야 한다.
		if (string_length + str.string_length < memory_capacity * 2)
			memory_capacity *= 2;
		else
			memory_capacity = string_length	+ str.string_length;


		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		// 일단 insert 되는 부분 직전까지의 내용을 복사한다.
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}

		// 그리고 새롭에 insert 되는 문자열을 넣는다.
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}

		// 이제 다시 원 문자열의 나머지 뒷부분을 복사한다.
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}

	// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없게 된다.
	// 효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

	for (int i = string_length - 1; i >= loc; i--) {
		// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게 함
		string_content[i + str.string_length] = string_content[i];
	}
	// 그리고 insert 되는 문자 다시 집어넣기
	for (int i = 0; i < str.string_length; i++)
		string_content[i + loc] = str.string_content[i];

	string_length = string_length + str.string_length;
	return *this;
	return *this;
}
MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
	if (num < 0 || loc < 0 || loc > string_length) return *this;
	for (int i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}
	string_length -= num;
	return *this;
}

int MyString::find(int find_from, const MyString& str) const {
	int i, j;
	if (str.string_length == 0) return -1;
	for (i = find_from; i < string_length - str.string_length; i++) {
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) break;
		}

		if (j == str.string_length) return i;
	}

	return -1;  // 찾지 못했음
}

int MyString::find(int find_from, const char* str) const {
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
	for (int i = 0; i < std::min(string_length, str.string_length); i++) {
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}

	if (string_length == str.string_length) return 0;
	else if (string_length > str.string_length) 
		return 1;

	return -1;
}

int main() {
	MyString str1("abcdef");
	MyString str2("abcde");

	std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
	system("pause");
}