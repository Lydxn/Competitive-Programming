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

int dp[2002][2002], r[2001][2001], t[2001][2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int xh, yh, T, x, y, l; bool nx = false, ny = false;
	cin >> xh >> yh >> T;
	if (xh < 0) xh = -xh, nx = true;
	if (yh < 0) yh = -yh, ny = true;
	while (T--) {
		cin >> x >> y >> l;
		if (nx) x = -x;
		if (ny) y = -y;
		if (x + l >= 0 && x + l <= xh)
			for (int i = max(0, y - l); i <= min(y + l, yh); i++) ++r[x + l][i];
		if (y + l >= 0 && y + l <= yh)
			for (int i = max(0, x - l); i <= min(x + l, xh); i++) ++t[i][y + l];
	}
	memset(dp, INF, sizeof(dp)); dp[xh][yh] = 0;
	for (int i = xh; i >= 0; i--)
		for (int j = yh; j >= 0; j--)
			if (!(i == xh && j == yh))
				dp[i][j] = min(dp[i + 1][j] + r[i][j], dp[i][j + 1] + t[i][j]);
	cout << dp[0][0] << '\n';
	return 0;
}
