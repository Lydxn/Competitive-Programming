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

struct event {
	int x, y1, y2, type;
	bool operator< (event &e) { return x < e.x || (x == e.x && type < e.type); }
} ev[600000];
int BIT[600002], y[600000], eidx, yidx;
unordered_map<int, int> indy;

void update(int i, int x) {
	for (; i <= 600001; i += i & -i) BIT[i] += x;
}

int query(int i) {
	int res = 0;
	for (; i; i -= i & -i) res += BIT[i];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, x1, y1, x2, y2;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		// weird but ok?
		if (x1 > x2 || y1 > y2) continue;
		y[yidx++] = y1, y[yidx++] = y2;
		ev[eidx++] = {x1, y1, y2, 0}, ev[eidx++] = {x2, y1, y2, 2};
	}

	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1;
		y[yidx++] = y1;
		ev[eidx++] = {x1, y1, -1, 1};
	}

	sort(y, y + yidx);
	for (int i = 0; i < yidx; i++) indy[y[i]] = i + 1;

	sort(ev, ev + eidx); int ans = 0;
	for (int i = 0; i < eidx; i++) {
		int y1 = indy[ev[i].y1], y2 = indy[ev[i].y2];
		if (ev[i].type == 0) update(y1, 1), update(y2 + 1, -1);
		else if (ev[i].type == 1) ans += query(y1) > 0;
		else update(y1, -1), update(y2 + 1, 1);
	}
	cout << ans << '\n';
	return 0;
}
