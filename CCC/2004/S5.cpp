#include <bits/stdc++.h>

using namespace std;

char grid[101][101];
int m = 1, n = 1, dp[101][101][2][2];

int solve(int r, int c, bool upok, bool downok) {
	if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -1) return INT_MIN;
	if (r == m - 1 && c == n - 1) return grid[r][c];
	if (dp[r][c][upok][downok] != -1) return dp[r][c][upok][downok];

	int res = INT_MIN;
	if (upok) res = max(res, solve(r - 1, c, true, false));
	if (downok) res = max(res, solve(r + 1, c, false, true));
	res = max(res, solve(r, c + 1, true, true)) + grid[r][c];
	return dp[r][c][upok][downok] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	char ch;
	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) return 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> ch;
				if (ch == '.') grid[i][j] = 0;
				else if (ch == '*') grid[i][j] = -1;
				else grid[i][j] = ch - '0';
			}
		}

		memset(dp, -1, sizeof(dp));
		cout << solve(m - 1, 0, true, true) << '\n';
	}
}
