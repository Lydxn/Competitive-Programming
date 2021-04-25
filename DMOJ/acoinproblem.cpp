#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct qu {
	int c, l, i;
	bool operator< (const qu& q) const { return l < q.l; }
};

const int INF = 0x3f3f3f3f;
qu q[100000];
int dp[10001], d[2001], ans[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, V;
	cin >> N >> V;
	for (int i = 1; i <= N; i++) cin >> d[i];

	for (int i = 0; i < V; i++) {
		cin >> q[i].c >> q[i].l;
		q[i].i = i;
	}
	sort(q, q + V);

	memset(dp, INF, sizeof(dp)); dp[0] = 0;
	for (int i = 1, qi = 0; i <= N; i++) {
		for (int j = d[i]; j <= 10000; j++) dp[j] = min(dp[j], dp[j - d[i]] + 1);
		for (; qi < V && q[qi].l == i; qi++) ans[q[qi].i] = dp[q[qi].c] == INF ? -1 : dp[q[qi].c];
	}

	for (int i = 0; i < V; i++) cout << ans[i] << '\n';
	return 0;
}
