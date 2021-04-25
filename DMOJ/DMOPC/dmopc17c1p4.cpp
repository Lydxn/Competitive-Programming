#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[2][5001][2];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, H, g, h, q, t;
	cin >> N >> H;

	for (int i = 0; i < N; i++) {
		cin >> g >> h >> q >> t;
		for (int j = 0; j <= H; j++) {
			dp[i & 1][j][0] = j - h >= 0 ? max(dp[(i & 1) ^ 1][j][0], dp[i & 1][j - h][1] + g) : dp[(i & 1) ^ 1][j][0];
			dp[i & 1][j][1] = j - t >= 0 ? max(dp[(i & 1) ^ 1][j][0], dp[i & 1][j - t][1] + q) : dp[(i & 1) ^ 1][j][0];
		}
	}

	cout << dp[(N & 1) ^ 1][H][0] << '\n';
	return 0;
}
