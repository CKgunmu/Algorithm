#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool check = false;
vector<int> vec1(9);
int main(void) {
	
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> vec1[i];
		sum += vec1[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if ((sum - vec1[i] - vec1[j]) == 100) {
				vec1[i] = 1000000;
				vec1[j] = 1000000;
				check = true;
				break;
			}
		}
		if (check) break;
	}

	sort(vec1.begin(), vec1.end());
	for (int i = 0; i < 9; i++) {
		if (vec1[i] == 1000000) continue;
		
		cout << vec1[i] << endl;
	}
}