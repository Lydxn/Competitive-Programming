#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int t[3][150000], dp[3][150001], N;
int perm[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int solve(int x) {
	memset(dp, 0x3f, sizeof(dp));
	int a = perm[x][0], b = perm[x][1], c = perm[x][2];

	dp[a][0] = t[a][0];
	for (int i = 1; i < N; i++) {
		dp[a][i] = dp[a][i - 1] + t[a][i];
		dp[b][i] = min(dp[b][i - 1], dp[a][i - 1]) + t[b][i];
		dp[c][i] = min(dp[c][i - 1], dp[b][i - 1]) + t[c][i];
	}
	return dp[c][N - 1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < N; j++)
			cin >> t[i][j];

	int ans = INT_MAX;
	for (int i = 0; i < 6; i++)
		ans = min(ans, solve(i));
	cout << ans << '\n';
	return 0;
}
