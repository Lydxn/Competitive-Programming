#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int c[1000], v[1000], t[1000], dp[3001][1 << 5];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, B, ans = -1;
	cin >> T >> N;
	for (int i = 0; i < N; i++) cin >> c[i] >> v[i] >> t[i], --t[i];
	cin >> B;

	for (int i = 0; i < N; i++) {
		for (int j = B; j >= c[i]; j--) {
			for (int k = 0; k < (1 << T); k++) {
				if (!(k & (1 << t[i]))) {
					dp[j][k | (1 << t[i])] = max(dp[j][k | (1 << t[i])], dp[j - c[i]][k] + v[i]);\
				}
			}
		}
	}

	for (int i = 0; i <= B; i++) ans = max(ans, dp[i][(1 << T) - 1]);
	cout << ans << '\n';
	return 0;
}
