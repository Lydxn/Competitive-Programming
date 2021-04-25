#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dp[2][5000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string S;
	cin >> N >> S;

	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j < N; j++) {
			dp[(i & 1) ^ 1][j] = S[i] == S[j] ? dp[i & 1][j - 1] : 1 + min(dp[(i & 1) ^ 1][j - 1], dp[i & 1][j]);
		}
	}
	cout << dp[1][N - 1] << '\n';
	return 0;
}
