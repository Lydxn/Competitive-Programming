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

int a[200001], lzs[600001];
ll seg[600001], lza[600001];

void build(int si, int ss, int se) {
	if (ss == se) { seg[si] = a[ss]; return; }
	int mid = (ss + se) >> 1;
	build(si << 1, ss, mid), build(si << 1 | 1, mid + 1, se);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

void push(int si, int ss, int se) {
	if (lzs[si] != 0) {
		seg[si << 1] = seg[si << 1 | 1] = lzs[si];
		lzs[si << 1] = lzs[si << 1 | 1] = lzs[si];
		lza[si << 1] = lza[si << 1 | 1] = 0;
		lzs[si] = 0;
	}
	if (lza[si] != 0) {
		seg[si << 1] += lza[si], seg[si << 1 | 1] += lza[si];
		lza[si << 1] += lza[si], lza[si << 1 | 1] += lza[si];
		lza[si] = 0;
	}
}

void updatea(int si, int ss, int se, int l, int r, int v) {
	if (se < l || ss > r) return;
	if (ss >= l && se <= r) {
		seg[si] += v, lza[si] += v;
		return;
	}
	push(si, ss, se);
	int mid = (ss + se) >> 1;
	updatea(si << 1, ss, mid, l, r, v), updatea(si << 1 | 1, mid + 1, se, l, r, v);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

void updates(int si, int ss, int se, int l, int r, int v) {
	if (se < l || ss > r) return;
	if (ss >= l && se <= r) {
		seg[si] = v, lzs[si] = v, lza[si] = 0;
		return;
	}
	push(si, ss, se);
	int mid = (ss + se) >> 1;
	updates(si << 1, ss, mid, l, r, v), updates(si << 1 | 1, mid + 1, se, l, r, v);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

ll query(int si, int ss, int se, int l, int r) {
	if (se < l || ss > r) return INFL;
	if (ss >= l && se <= r) return seg[si];
	push(si, ss, se);
	int mid = (ss + se) >> 1;
	return min(query(si << 1, ss, mid, l, r), query(si << 1 | 1, mid + 1, se, l, r));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, op, l, r, v;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> a[i];
	build(1, 1, N);
	while (Q--) {
		cin >> op >> l >> r;
		if (op == 1) cin >> v, updatea(1, 1, N, l, r, v);
		else if (op == 2) cin >> v, updates(1, 1, N, l, r, v);
		else cout << query(1, 1, N, l, r) << '\n';
	}
	return 0;
}