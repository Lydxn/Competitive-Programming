#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[2][701 * 701];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, A, sum = 0, ans = INT_MAX;
	cin >> N;

	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> A, sum += A;
		for (int j = A; j <= sum; j++) {
			dp[i & 1][j] |= dp[(i & 1) ^ 1][j] | dp[(i & 1) ^ 1][j - A];
		}
	}


	for (int i = 0; i <= sum; i++) {
		if (dp[N & 1][i]) ans = min(ans, abs(i - (sum - i)));
	}

	cout << ans << '\n';
	return 0;
}
