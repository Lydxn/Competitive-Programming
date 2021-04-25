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

int X, Y, m[1000001];
ll ans[1000001];
struct team {
	int i, dx, dy; ll mag;
	team() {}
	team(int _i, int _x, int _y) {
		i = _i, dx = _x - X, dy = _y - Y;
		mag = (ll) dx * dx + (ll) dy * dy;
		int g = abs(__gcd(dx, dy)); dx /= g, dy /= g;
	}
	bool operator< (const team& t) {
		return dx < t.dx || (dx == t.dx && dy < t.dy) || (dx == t.dx && dy == t.dy && mag < t.mag);
	}
} ts[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, t, x, y;
	cin >> N >> Q >> X >> Y;
	for (int i = 1; i <= N; i++)
		cin >> x >> y >> m[i], ts[i] = team(i, x, y);
	
	sort(ts + 1, ts + N + 1);
	for (int i = 1; i <= N; ) {
		int cur = i; ll sum = 0;
		while (cur <= N && ts[cur].dx == ts[i].dx && ts[cur].dy == ts[i].dy)
			sum += m[ts[cur].i], ans[ts[cur].i] = sum, ++cur;
		i = cur;
	}
	
	while (Q--) {
		cin >> t;
		cout << ans[t] << '\n';
	}
	return 0;
}
