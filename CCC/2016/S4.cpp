// i guess O(N^4) passes?

#include <bits/stdc++.h>

using namespace std;

int dp[401][401], balls[401], psa[401];

bool can(int l, int r) {
	if (l >= r) return true;
	if (dp[l][r] != -1) return dp[l][r];

	bool res = false;
	for (int i = l; i <= r; i++) {
		for (int j = i; j <= r; j++) {
			if (psa[i] - psa[l - 1] == psa[r] - psa[j - 1]) {
				res |= can(l, i) & can(i + 1, j - 1) & can(j, r);
			}
		}
	}
	return dp[l][r] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> balls[i], psa[i] = psa[i - 1] + balls[i];

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			if (can(i, j)) ans = max(ans, psa[j] - psa[i - 1]);
		}
	}
	cout << ans << '\n';
	return 0;
}
