#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dp[2][16], s[4];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[0] >> s[1] >> s[2] >> s[3];
		for (int k = 0; k < 16; k++) {
			dp[i & 1][k] = dp[(i & 1) ^ 1][k];
			for (int j = 0; j < 4; j++) {
				if (s[j] != -1 && k & (1 << j)) {
					dp[i & 1][k] = max(dp[i & 1][k], dp[(i & 1) ^ 1][k ^ (1 << j)] + s[j]);
				}
			}
		}
	}
	cout << dp[(N & 1) ^ 1][15] << '\n';
	return 0;
}
