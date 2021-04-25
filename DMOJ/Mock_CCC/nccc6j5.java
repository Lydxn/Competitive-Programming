#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
int cnt[1001];
ll dp[1001][1001];

ll solve(int N, int K) {
	if (K == 0) return 1;
	if (N == 0) return 0;
	if (dp[N][K] != -1) return dp[N][K];
	return dp[N][K] = (solve(N - 1, K) + cnt[N] * solve(N - 1, K - 1) % MOD) % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, f;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> f, ++cnt[f];

	memset(dp, -1, sizeof(dp));
	cout << solve(N, K) << '\n';
	return 0;
}
