#include <stdio.h>
#define min(a,b) (a)<(b)?(a):(b)

int n, m, i, j, a, b, ans = 1e9;
char str[55][55];

int main() {
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%s", str[i]);

	for (i = 0; i < n - 7; i++) {
		for (j = 0; j < m - 7; j++) {
			int cnt = 0;
			for (a = i; a < i + 8; a++) {
				for (b = j; b < j + 8; b++) {
					cnt += str[a][b] == ((a & 1) ^ (b & 1) ? 'W' : 'B');
				}
				ans = min(ans, min(cnt, 64 - cnt));
			}
		}
	}

	printf("%d", ans);

	return 0;
}
