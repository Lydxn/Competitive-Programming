// 70/80 WA :(

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

struct pt {
	double x, y;
	bool operator< (const pt &p) const { return x < p.x || (x == p.x && y < p.y); }
} p[100000], h[100001];
int hidx;

double ccw(pt a, pt b, pt c) {
	return (a.x - b.x) * (b.y - c.y) - (a.y - b.y) * (b.x - c.x);
}

pt perp(pt a, pt b, pt c) {
	double d = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	double v = ((c.x - a.x) * (b.x - a.x) + (c.y - a.y) * (b.y - a.y)) / d;
	return {a.x + v * (b.x - a.x), a.y + v * (b.y - a.y)};
}


double pdist(pt a, pt b, pt c) {
	return abs((b.x - a.x) * (a.y - c.y) - (a.x - c.x) * (b.y - a.y))
		/ sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;
	sort(p, p + N);
	for (int i = 0; i < N; h[hidx++] = p[i++])
		while (hidx >= 2 && ccw(h[hidx - 2], h[hidx - 1], p[i]) >= 0) --hidx;
	for (int i = N - 2, l = hidx + 1; i >= 0; h[hidx++] = p[i--])
		while (hidx >= l && ccw(h[hidx - 2], h[hidx - 1], p[i]) >= 0) --hidx;
	--hidx;
	double ans = INFL;
	for (int i = 0, a = 1, b = 1, c = 1; i < hidx; i++) {
		pt l1 = h[i], l2 = h[(i + 1) % hidx]; double da, db, dc;
		while ((da = pdist(l1, l2, h[a % hidx])) < pdist(l1, l2, h[(a + 1) % hidx])) ++a;
		pt lx = h[a % hidx], ly = perp(l1, l2, lx);
		b = max(b, i);
		while ((db = pdist(lx, ly, h[b % hidx])) < pdist(lx, ly, h[(b + 1) % hidx])) ++b;
		c = max(c, a);
		while ((dc = pdist(lx, ly, h[c % hidx])) < pdist(lx, ly, h[(c + 1) % hidx])) ++c;
		ans = min(ans, da * (db + dc));
	}
	cout << (ll) round(ans) << '\n';
	return 0;
}