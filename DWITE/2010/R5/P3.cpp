#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool dp[500001];
int w[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) {
		int N, S = 0;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> w[i], S += w[i];

		memset(dp, false, sizeof(dp)); dp[0] = true;
		for (int i = 0; i < N; i++) {
			for (int j = S / 2; j >= w[i]; j--) {
				dp[j] |= dp[j - w[i]];
			}
		}

		for (int i = S / 2; i >= 0; i--) {
			if (dp[i]) {
				cout << abs(i - (S - i)) << '\n';
				break;
			}
		}
	}
	return 0;
}
