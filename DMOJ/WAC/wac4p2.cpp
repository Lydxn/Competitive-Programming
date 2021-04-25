#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int v[5001], p[5001];
ll dp[5001][5001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, W = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> v[i] >> p[i], v[i] = v[i] / 2 + 1, W += p[i];

	W = W / 2 + 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 5000; j++) {
			dp[i][j] = 1e15;
		}
	}

	for (int i = 0; i <= N; i++) dp[i][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 5000; j++) {
			dp[i][j] = j - p[i] < 0 ? dp[i - 1][j] : min(dp[i - 1][j], dp[i - 1][j - p[i]] + v[i]);
		}
	}

	ll ans = LLONG_MAX;
	for (int i = W; i <= 5000; i++) ans = min(ans, dp[N][i]);
	cout << ans << '\n';
	return 0;
}
