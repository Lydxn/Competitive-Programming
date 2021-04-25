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

	int t, a, b, c, d, x, y, x1, y1, x2, y2;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
		cout << (x1 <= x - a + b && x - a + b <= x2 && (x1 != x2 || a + b == 0) && y1 <= y - c + d && y - c + d <= y2 && (y1 != y2 || c + d == 0) ? "YES" : "NO") << '\n';
	}
	return 0;
}
