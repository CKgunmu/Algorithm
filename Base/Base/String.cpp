#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

class MyString {
	char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
	int string_length;     // ���ڿ� ����
	int memory_capacity;   // ���� �Ҵ�� �뷮

public:
	MyString(char c);					// ���� �ϳ��� ����
	MyString(const char* str);			// ���ڿ��� ���� ����
	MyString(const MyString& str);		// ���� ������
	~MyString();						// �����Ҵ�����

	MyString& assign(const char* str);	// ���ڿ��� ���� ����
	MyString& assign(const MyString& str); // ���� ������
	
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	MyString& erase(int loc, int num);

	int length() const;					// ���ڿ� ��� ���
	int capacity() const;				// �뷮���
	int find(int find_from, const MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;
	int compare(const MyString& str) const;

	char at(int i) const;				// ���ڿ� ��ġ

	void reserve(int size);				// �޸� �Ҵ� 
	void print() const;					// ���
	void println() const;				// ��� �� ����
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
	// �̴� i �� ��ġ �ٷ� �տ� ���ڸ� �����ϰ� �ȴ�. ���� ��
	// abc ��� ���ڿ��� insert(1, "d") �� �ϰ� �ȴٸ� adbc �� �ȴ�.

	// ������ ����� �Է¿� ���ؼ��� ������ �������� �ʴ´�.
	if (loc < 0 || loc > string_length) {
		return *this;
	}

	if (string_length + str.string_length > memory_capacity) {
		// ���� ���Ӱ� �������� �Ҵ��� �ؾ� �Ѵ�.
		if (string_length + str.string_length < memory_capacity * 2)
			memory_capacity *= 2;
		else
			memory_capacity = string_length	+ str.string_length;


		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		// �ϴ� insert �Ǵ� �κ� ���������� ������ �����Ѵ�.
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}

		// �׸��� ���ӿ� insert �Ǵ� ���ڿ��� �ִ´�.
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}

		// ���� �ٽ� �� ���ڿ��� ������ �޺κ��� �����Ѵ�.
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}

	// ���� �ʰ����� �ʴ� ��� ���� �����Ҵ��� �� �ʿ䰡 ���� �ȴ�.
	// ȿ�������� insert �ϱ� ����, �и��� �κ��� ���� �ڷ� �о������.

	for (int i = string_length - 1; i >= loc; i--) {
		// �ڷ� �б�. �� �� ������ ���ڿ� �����Ͱ� ������� �ʰ� ��
		string_content[i + str.string_length] = string_content[i];
	}
	// �׸��� insert �Ǵ� ���� �ٽ� ����ֱ�
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

	return -1;  // ã�� ������
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