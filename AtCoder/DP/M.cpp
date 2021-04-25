#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;
ll dp[101][100001], sum[100002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, a;
	cin >> N >> K;

	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		for (int j = 1; j <= K + 1; j++) sum[j] = (sum[j - 1] + dp[i - 1][j - 1]);
		for (int j = 0; j <= K; j++) dp[i][j] = (dp[i][j] + sum[j + 1] - sum[max(j - a, 0)]) % MOD;
	}

	cout << dp[N][K] << '\n';
	return 0;
}
