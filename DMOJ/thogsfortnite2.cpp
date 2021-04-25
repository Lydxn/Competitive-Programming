#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int H, D[1000], A[1000], W[1000], dp[1000][10001], tmp[10001], len[1000];
vector<int> adj[1000];

void dfs(int cur, int prev) {
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dfs(i, cur);

		int nlen = min(H, len[cur] + len[i] + W[cur]);
		memset(tmp, -INF, (nlen + 1) << 2);
		memcpy(tmp, dp[cur], (len[cur] + 1) << 2);
		for (int j = 0; j <= len[cur]; j++) {
			for (int k = 0; k <= len[i]; k++) {
				int jk = j + k + W[cur];
				if (jk <= nlen)
					tmp[jk] = max(tmp[jk], dp[cur][j] + dp[i][k]);
			}
		}
		memcpy(dp[cur], tmp, (nlen + 1) << 2);
		len[cur] = nlen;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, X, Y, t, p;
	cin >> H >> N;
	for (int i = 0; i < N; i++) {
		cin >> D[i] >> A[i] >> W[i];
		memset(dp[i], -INF, sizeof(dp[i])); len[i] = W[i] + D[i], dp[i][0] = 0;
		for (int j = 0; j < A[i]; j++) {
			cin >> t >> p;
			for (int k = D[i]; k >= t; k--)
				dp[i][k] = max(dp[i][k], dp[i][k - t] + p);
		}
		memcpy(dp[i] + W[i], dp[i], (D[i] + 1) << 2);
		memset(dp[i], -INF, W[i] << 2);
	}

	for (int i = 0; i < N - 1; i++) {
		cin >> X >> Y;
		adj[X].push_back(Y), adj[Y].push_back(X);
	}

	dfs(0, -1);
	int mx = 0;
	for (int i = 0; i <= H; i++) mx = max(mx, dp[0][i]);
	cout << mx << '\n';
	return 0;
}
