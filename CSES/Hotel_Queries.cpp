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

int h[200001], seg[600001];

void build(int si, int ss, int se) {
	if (ss == se) { seg[si] = h[ss]; return; }
	int mid = (ss + se) >> 1;
	build(si << 1, ss, mid), build(si << 1 | 1, mid + 1, se);
	seg[si] = max(seg[si << 1], seg[si << 1 | 1]);
}

void update(int si, int ss, int se, int i, int v) {
	if (se < i || ss > i) return;
	if (ss == se) { seg[si] -= v; return; }
	int mid = (ss + se) >> 1;
	update(si << 1, ss, mid, i, v), update(si << 1 | 1, mid + 1, se, i, v);
	seg[si] = max(seg[si << 1], seg[si << 1 | 1]);
}

int query(int si, int ss, int se, int r) {
	if (seg[si] < r) return 0;
	while (ss != se) {
		int mid = (ss + se) >> 1;
		if (seg[si << 1] >= r) si <<= 1, se = mid;
		else si = si << 1 | 1, ss = mid + 1;
	}
	return ss;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> h[i];
	build(1, 1, n);
	while (m--) {
		cin >> r;
		int ans = query(1, 1, n, r);
		cout << ans << ' ';
		update(1, 1, n, ans, r);
	}
	cout << '\n';
	return 0;
}
