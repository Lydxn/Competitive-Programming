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

int p[200001], seg1[600001], seg2[600001];

void build(int si, int ss, int se) {
	if (ss == se) { seg1[si] = p[ss] + ss, seg2[si] = p[ss] - ss; return; }
	int mid = (ss + se) >> 1;
	build(si << 1, ss, mid), build(si << 1 | 1, mid + 1, se);
	seg1[si] = min(seg1[si << 1], seg1[si << 1 | 1]), seg2[si] = min(seg2[si << 1], seg2[si << 1 | 1]);
}

void update(int si, int ss, int se, int a, int b) {
	if (se < a || ss > a) return;
	if (ss == se) { seg1[si] = b + a, seg2[si] = b - a; return; }
	int mid = (ss + se) >> 1;
	update(si << 1, ss, mid, a, b),update(si << 1 | 1, mid + 1, se, a, b);
	seg1[si] = min(seg1[si << 1], seg1[si << 1 | 1]), seg2[si] = min(seg2[si << 1], seg2[si << 1 | 1]);
}

int query(int si, int ss, int se, int a, int b, int t) {
	if (se < a || ss > b) return INF;
	if (ss >= a && se <= b) return t ? seg2[si] : seg1[si];
	int mid = (ss + se) >> 1;
	return min(query(si << 1, ss, mid, a, b, t), query(si << 1 | 1, mid + 1, se, a, b, t));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, op, a, b;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> p[i];
	build(1, 1, n);
	while (q--) {
		cin >> op >> a;
		if (op == 1) cin >> b, update(1, 1, n, a, b);
		else cout << min(query(1, 1, n, a, n, 0) - a, query(1, 1, n, 1, a, 1) + a) << '\n';
	}
	return 0;
}
