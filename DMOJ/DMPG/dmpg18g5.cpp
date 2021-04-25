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
} p[4000], h[8000];
int hidx;

int ccw(point &a, point &b, point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int dist(point &a, point &b, point &c) {
	return abs(a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;
	sort(p, p + N);
	
	for (int i = 0; i < N; h[hidx++] = p[i++])
		while (hidx >= 2 && ccw(h[hidx - 2], h[hidx - 1], p[i]) <= 0) --hidx;
	for (int i = N - 2, t = hidx + 1; i >= 0; h[hidx++] = p[i--])
		while (hidx >= t && ccw(h[hidx - 2], h[hidx - 1], p[i]) <= 0) --hidx;
	--hidx, memcpy(h + hidx, h, hidx << 4);

	for (int i = 0; i < hidx; i++) {
		for (int j = i + 1, k = i + 2; j < k; j++) {
			int d = dist(h[i], h[j], h[k]), nxt;
			while (d < (nxt = dist(h[i], h[j], h[k + 1]))) ++k, d = nxt;
			ans = max(ans, d);
		}
	}
	cout << fixed << setprecision(6) << ans / 2.0 << '\n';
	return 0;
}
