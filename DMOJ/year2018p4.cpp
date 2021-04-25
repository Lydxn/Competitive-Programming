#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXSUM = 162, MAXDIG = 20;
ll dp[MAXDIG][MAXSUM + 1];
int dig[MAXDIG];

ll solve(int pos, int sum, bool tight = true) {
	if (sum < 0) return 0;
	if (pos == 0) return sum == 0;
	if (!tight && dp[pos][sum] != -1) return dp[pos][sum];

	ll res = 0;
	for (int i = 0; i <= (tight ? dig[pos] : 9); i++) res += solve(pos - 1, sum - i, tight && dig[pos] == i);
	return tight ? res : dp[pos][sum] = res;
}

// count numbers less than or equal to N with a sum of s.
ll f(ll N, int s) {
	int pos = 0;
	while (N) dig[++pos] = N % 10, N /= 10;
	return solve(pos, s);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll L, R; int ans = 0;
    cin >> L >> R;

	memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= MAXSUM; i++) ans += f(L - 1, i) < f(R, i);

    cout << ans << '\n';
    return 0;
}
