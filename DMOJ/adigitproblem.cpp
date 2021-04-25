#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;
int dp[1000][1024][2][2], mask;
string K;

int solve(int pos, int cmask, bool tight, bool nonz) {
	if (pos == int(K.size())) return (mask & cmask) == mask;
	if (dp[pos][cmask][tight][nonz] != -1) return dp[pos][cmask][tight][nonz];

	ll res = 0;
	for (int i = 0, k = tight ? K[pos] - '0' : 9; i <= k; i++)
		res = (res + solve(pos + 1, nonz || i ? cmask | (1 << i) : cmask, K[pos] - '0' == i ? tight : false, nonz || i)) % MOD;
	return dp[pos][cmask][tight][nonz] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a, mask |= 1 << a;
	cin >> K;

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, true, false) + (mask == 1) << '\n';
	return 0;
}
