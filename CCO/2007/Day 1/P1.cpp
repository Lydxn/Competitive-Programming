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

struct point {
	int x, y;
	bool operator< (const point &p) { return x < p.x || (x == p.x && y < p.y); }
} p[10000], h[20000];
int hidx;

int ccw(point &a, point &b, point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	sort(p, p + n);
	for (int i = 0; i < n; h[hidx++] = p[i++])
		while (hidx >= 2 && ccw(h[hidx - 2], h[hidx - 1], p[i]) <= 0) --hidx;
	for (int i = n - 2, t = hidx + 1; i >= 0; h[hidx++] = p[i--])
		while (hidx >= t && ccw(h[hidx - 2], h[hidx - 1], p[i]) <= 0) --hidx;

	int ans = 0;
	for (int i = 1; i < hidx; i++) ans += h[i - 1].x * h[i].y - h[i - 1].y * h[i].x;
	cout << ans / 100 << '\n';
	return 0;
}
