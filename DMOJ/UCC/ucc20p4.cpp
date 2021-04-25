#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int b[1000001], dp[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> b[i];

	memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] =
			min(dp[i - 1] + b[i],
			min(dp[i - 2] + b[i - 1] + b[i] - min(b[i - 1], b[i]) / 4,
				dp[i - 3] + b[i - 2] + b[i - 1] + b[i] - min(b[i - 2], min(b[i - 1], b[i])) / 2));
	}
	cout << dp[N] << '\n';
	return 0;
}
