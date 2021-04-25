// for those who are afraid of segtree

#include <stdio.h>

int d[17][150002], A[150001], X[150000], Y[150000], Z[150000];

int gcd(int u, int v) {
	int s = __builtin_ctz(u | v);
	u >>= __builtin_ctz(u);
	do {
		v >>= __builtin_ctz(v);
		if (u > v) { int t = v; v = u; u = t; }  
		v = v - u;
	} while (v);
	return u << s;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", X + i, Y + i, Z + i);
		++d[Z[i]][X[i]], --d[Z[i]][Y[i] + 1];
	}

	for (int i = 1; i <= N; i++) A[i] = 1;
	for (int i = 2; i <= 16; i++) {
		for (int j = 1, s = 0; j <= N; j++) {
			if (s += d[i][j]) A[j] = A[j] * i / gcd(A[j], i);
			d[i][j] = !s;
		}
	}

	for (int i = 2; i <= 16; i++)
		for (int j = 1; j <= N; j++)
			d[i][j] += d[i][j - 1];
	
	for (int i = 0; i < M; i++) {
		int res = 1;
		for (int j = 2; j <= 16; j++)
			if (d[j][Y[i]] - d[j][X[i] - 1] == 0)
				res = res * j / gcd(res, j);
		if (res != Z[i])
			return 0 * printf("Impossible\n");
	}

	for (int i = 1; i <= N; i++)
		printf("%d ", A[i]);
	printf("\n");
}