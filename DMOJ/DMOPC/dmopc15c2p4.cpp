#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll R[100000], L[100000], H[100000], dp[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> R[i] >> L[i] >> H[i];

	for (int i = N - 1; i >= 0; i--) dp[i] = max(dp[i + 1], dp[lower_bound(R, R + N, R[i] + L[i]) - R] + H[i]);
	cout << dp[0] << '\n';
	return 0;
}
