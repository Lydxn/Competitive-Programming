// this solution somehow passes so i'll hold off on the honvex-cull shtick

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int T[10000], F[10000], PSAT[10001], PSAF[10001], dp[10001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> T[i] >> F[i];
	for (int i = N - 1; i >= 0; i--) PSAT[i] = PSAT[i + 1] + T[i], PSAF[i] = PSAF[i + 1] + F[i];

	memset(dp, 0x3f, sizeof(dp)); dp[N] = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N; j > i; j--) {
			dp[i] = min(dp[i], dp[j] + (S + PSAT[i] - PSAT[j]) * PSAF[i]);
		}
	}
	cout << dp[0] << '\n';
	return 0;
}
