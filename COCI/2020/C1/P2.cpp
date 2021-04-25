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

int n, m, dp[300][300];
string s, t;

int solve(int i, int j) {
	if (j == m) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int res = INF;
	for (int k = 0; k < n; k++) {
		if (s[k] != s[i]) continue;
		for (int d : {1, -1})
			if (k + d >= 0 && k + d < n && s[k + d] == t[j])
				res = min(res, solve(k + d, j + 1) + abs(i - k) + 1);
	}
	return dp[i][j] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s >> t;
	memset(dp, -1, sizeof(dp));
	int ans = INF;
	for (int i = 0; i < n; i++)
		if (s[i] == t[0]) ans = min(ans, solve(i, 1));
	cout << (ans == INF ? -1 : ans) << '\n';
	return 0;
}
