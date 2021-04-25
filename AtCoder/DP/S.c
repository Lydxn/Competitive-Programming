#include <stdio.h>
#include <string.h>

char K[10000];
int dp[10001][100][2];
const int MOD = 1e9 + 7;

void add(int *a, int b) {
	if ((*a += b) >= MOD) *a -= MOD;
}

int main() {
	int D, L;
	scanf("%s%d", K, &D);
	L = strlen(K), dp[0][0][0] = 1;
	for (int i = 0; i < L; i++)
		for (int j = 0; j < D; j++)
			for (int k = 0; k < 2; k++)
				for (int l = 0; l <= (k ? 9 : K[i] - '0'); l++)
					add(&dp[i + 1][(j + l) % D][k || l < K[i] - '0'], dp[i][j][k]);
	printf("%d\n", (dp[L][0][0] + dp[L][0][1] - 1) % MOD);
	return 0;
}
