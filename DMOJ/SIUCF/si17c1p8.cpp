#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dp[16][1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, t, a;
	cin >> n >> t;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 0; j <= t; j++) dp[i][j] = (j - a < 0 ? 0 : dp[i - 1][j - a]) + dp[i - 1][j];
	}
	cout << dp[n][t] << '\n';
	return 0;
}
