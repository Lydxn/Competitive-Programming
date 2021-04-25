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
using order1d_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

bool G[15][15];
int R, C, dp[15][15][2];

int solve(int r, int c, int col) {
	if (r == R - 1 && c == C - 1) return 1;
	if (dp[r][c][col] != -1) return dp[r][c][col];
	int res = 0;
	for (int i = r + 1; i < R; i++)
		for (int j = c + 1; j < C; j++)
			if (G[i][j] != col) res += solve(i, j, G[i][j]);
	return dp[r][c][col] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);

	cin >> R >> C; char c;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> c, G[i][j] = c == 'R';

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, G[0][0]) << '\n';
	return 0;
}
