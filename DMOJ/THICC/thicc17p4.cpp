#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dp[101][101];
string s0, s1;

int solve(int n, int m) {
	for (int i = 0; i <= n; i++) dp[i][0] = i;
	for (int i = 0; i <= m; i++) dp[0][i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s0[i - 1] == s1[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
	}
	return dp[n][m];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, t; double ans = DBL_MAX;
	cin >> s0 >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		int sum = 0;
		for (int j = 0; j < t; j++) {
			cin >> s1;
			sum += solve(s0.size(), s1.size());
		}
		ans = min(ans, (double) sum / t);
	}
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}
