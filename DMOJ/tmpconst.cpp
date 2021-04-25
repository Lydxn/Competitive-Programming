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
	ll x, y; int i;
	bool operator< (point &p) { return x < p.x || (x == p.x && y < p.y); };
	point operator- (point &p) { return {x - p.x, y - p.y}; }
	ll operator* (point &p) { return x * p.y - y * p.x; }
} pt[800];

struct segment {
	point p; int a, b;
	bool operator< (segment &s) { return p * s.p > 0; }
} seg[319600];
int pos[800], sidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll K;
	cin >> N >> K; K <<= 1;
	for (int i = 0; i < N; i++) cin >> pt[i].x >> pt[i].y, pt[i].i = i, pos[i] = i;
	sort(pt, pt + N);

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			seg[sidx++] = {pt[j] - pt[i], i, j};
	sort(seg, seg + sidx);

	ll mn = LLONG_MAX; int ans0 = -1, ans1 = -1, ans2 = -1, ans3 = -1;
	for (int i = 0; i < sidx; i++) {
		int &a = pos[seg[i].a], &b = pos[seg[i].b];
		int tmp0 = pt[a].x - pt[b].x, tmp1 = pt[a].y - pt[b].y;

		int l = 0, r = b + 1;
		while (l < a && r < N) {
			ll A = abs(tmp0 * (pt[l].y - pt[r].y) - (pt[l].x - pt[r].x) * tmp1);
			if (abs(A - K) < mn)
				ans0 = pt[a].i, ans1 = pt[l].i, ans2 = pt[b].i, ans3 = pt[r].i, mn = abs(A - K);
			++(A > K ? l : r);
		}
		swap(a, b), swap(pt[a], pt[b]);
	}

	cout << ans0 + 1 << ' ' << ans1 + 1 << ' ' << ans2 + 1 << ' ' << ans3 + 1 << '\n';
	return 0;
}
