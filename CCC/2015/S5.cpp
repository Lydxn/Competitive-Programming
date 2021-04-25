#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, M, A[3005], B[105], dp[3005][105][105][2];

int solve(int idx, int l, int r, bool good) {
	int& cur = dp[idx][l][r][good];
	if (cur != -1) return cur;

	if (idx == N + 1)
		return cur = l > r ? 0 : good ? B[r] + solve(idx, l, r - 1, false) : solve(idx, l + 1, r, true);
	if (good) {
		cur = max(cur, max(solve(idx, l, r, false), A[idx] + solve(idx + 1, l, r, false)));
		if (l <= r) cur = max(cur, B[r] + solve(idx, l, r - 1, false));
	} else {
		cur = solve(idx + 1, l, r, true);
		if (l <= r) cur = max(cur, solve(idx, l + 1, r, true));
	}
	return cur;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> B[i];

	sort(B + 1, B + M + 1);
	memset(dp, -1, sizeof(dp));

	cout << solve(1, 1, M, 1) << '\n';
	return 0;
}
