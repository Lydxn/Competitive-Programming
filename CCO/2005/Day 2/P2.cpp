#include <bits/stdc++.h>

using namespace std;

int l[20001], r[20001], dp[2][20001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

	dp[0][0] = r[0] + r[0] - l[0], dp[1][0] = r[0];
	for (int i = 1; i < n; i++) {
		dp[0][i] = min(dp[0][i - 1] + abs(l[i - 1] - r[i]) + r[i] - l[i], dp[1][i - 1] + abs(r[i - 1] - r[i]) + r[i] - l[i]) + 1;
		dp[1][i] = min(dp[0][i - 1] + abs(l[i - 1] - l[i]) + r[i] - l[i], dp[1][i - 1] + abs(r[i - 1] - l[i]) + r[i] - l[i]) + 1;
	}

	cout << dp[1][n - 1] + n - r[n - 1] - 1 << '\n';
	return 0;
}
