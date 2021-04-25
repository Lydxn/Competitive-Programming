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
	ll x, y;
	bool operator< (const point &p) { return x < p.x || (x == p.x && y < p.y); }
} p[200000], h[200000];
int hidx;

ll ccw(point a, point b, point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dist(point a, point b, point c) {
	ll d = abs((c.y - b.y) * a.x - (c.x - b.x) * a.y + c.x * b.y - c.y * b.x);
	return d / sqrt((c.y - b.y) * (c.y - b.y) + (c.x - b.x) * (c.x - b.x));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, R;
	cin >> N >> R;
	for (int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;
	sort(p, p + N);
	
	for (int i = 0; i < N; h[hidx++] = p[i++])
		while (hidx >= 2 && ccw(h[hidx - 2], h[hidx - 1], p[i]) <= 0) --hidx;
	for (int i = N - 2, t = hidx + 1; i >= 0; h[hidx++] = p[i--])
		while (hidx >= t && ccw(h[hidx - 2], h[hidx - 1], p[i]) <= 0) --hidx;
	
	double ans = LLONG_MAX;
	for (int i = 1, j = 2, m = hidx - 1; i <= m; i++) {
		double d;
		while ((d = dist(h[j % m], h[i], h[i - 1])) < dist(h[(j + 1) % m], h[i], h[i - 1])) ++j;
		ans = min(ans, d);
	}
	cout << fixed << setprecision(16) << ans << '\n';
	return 0;
}
