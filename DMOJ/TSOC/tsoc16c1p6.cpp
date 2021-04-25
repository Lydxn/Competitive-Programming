#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string S, T;
int dp[1001][1001];

int solve(int N, int M) {
	if (N < 0 || M < 0) return 9999;
	if (N == 0 && M == 0) return 0;
	if (dp[N][M] != -1) return dp[N][M];
	if (S[N - 1] == T[M - 1]) return solve(N - 1, M - 1);
	return dp[N][M] = 1 + min(solve(N - 1, M - 1), min(solve(N, M - 1), min(solve(N, M - 2), min(solve(N, M - 3), min(solve(N - 1, M), min(solve(N - 2, M), solve(N - 3, M)))))));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M >> S >> T;

	memset(dp, -1, sizeof(dp));
	cout << solve(N, M);
	return 0;
}
