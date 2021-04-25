#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[100001], b[100001], dp[100001][3];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= N; i++) cin >> b[i];

	for (int i = 1; i <= N; i++) {
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + b[i];
		dp[i][1] = dp[i - 1][0] + a[i], dp[i][2] = dp[i - 1][1] + a[i];
	}

	cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << '\n';
	return 0;
}
