#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dp[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) {
		int m, n, c;
		cin >> m >> n;

		memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> c;
			for (int j = c; j <= m; j++) dp[j] = min(dp[j], dp[j - c] + 1);
		}
		cout << dp[m] << '\n';
	}
	return 0;
}
