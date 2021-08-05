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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, W, H, x1, y1, x2, y2, w, h;
	cin >> t;
	while (t--) {
		cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
		int ans = INF;
		if (W - (x2 - x1) >= w) ans = min(ans, max(0, min(w - x1, w - W + x2)));
		if (H - (y2 - y1) >= h) ans = min(ans, max(0, min(h - y1, h - H + y2)));
		cout << (ans == INF ? -1 : ans) << '\n';
	}
	return 0;
}
