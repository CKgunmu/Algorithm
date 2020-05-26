#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 200 + 1;
int N, M;
int arr[MAX];

//부모 찾는 연산
int findParent(int num) {
	if (arr[num] < 0)
		return num;

	int parent = findParent(arr[num]);
	arr[num] = parent;
	return parent;
}

void merge(int aParent, int bParent) {
	//집합의 크기가 더 큰 쪽으로 합쳐진다
	if (abs(aParent) >= abs(bParent)) {
		arr[aParent] += arr[bParent];
		arr[bParent] = aParent;
	}

	else {
		arr[bParent] += arr[aParent];
		arr[aParent] = bParent;
	}

}



int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상
	cin >> N >> M;

	//초기에는 모든 원소의 부모가 자기 자신
	memset(arr, -1, sizeof(arr));

	//인접한 도시들끼리 한 집합으로 합쳐준다
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			int connected;
			cin >> connected;

			if (connected)	{
				int aParent = findParent(i);
				int bParent = findParent(j);
				if (aParent == bParent)
					continue;

				merge(aParent, bParent);
			}
		}

	int root;
	bool possible = true;

	//주어진 도시들이 모두 같은 집합에 있는지 확인
	for (int i = 0; i < M; i++) {
		int city;
		cin >> city;

		//첫 번째 도시의 루트를 찾아준다
		if (i == 0)
			root = findParent(city);

		else {
			if (root != findParent(city))
			{
				possible = false;
				break;
			}
		}
	}

	if (possible)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;

}