#include <stdio.h>
#include <vector>
using namespace std;

int tc, n, ans;
vector<int> v;

int main() {
	for (int i = 1; i*(i + 1) / 2 <= 1000; i++) v.push_back(i*(i + 1) / 2);
	for (scanf("%d", &tc); tc--;) {
		scanf("%d", &n); ans = 0;
		for (int i : v) for (int j : v) for (int k : v)
			if (i + j + k == n) ans = 1;
		printf("%d\n", ans);
	}

	return 0;
}
