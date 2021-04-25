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

int t[200001];
ll seg[600001], lza[600001], lzs[600001];

void build(int si, int ss, int se) {
	if (ss == se) { seg[si] = t[ss]; return; }
	int mid = (ss + se) >> 1;
	build(si << 1, ss, mid), build(si << 1 | 1, mid + 1, se);
	seg[si] = seg[si << 1] + seg[si << 1 | 1];
}

void push(int si, int ss, int se) {
	if (lzs[si] != 0) {
		int mid = (ss + se) >> 1;
		seg[si << 1] = (mid - ss + 1) * lzs[si], seg[si << 1 | 1] = (se - mid) * lzs[si];
		lzs[si << 1] = lzs[si << 1 | 1] = lzs[si];
		lza[si << 1] = lza[si << 1 | 1] = 0;
		lzs[si] = 0;
	}
	if (lza[si] != 0) {
		int mid = (ss + se) >> 1;
		seg[si << 1] += (mid - ss + 1) * lza[si], seg[si << 1 | 1] += (se - mid) * lza[si];
		lza[si << 1] += lza[si], lza[si << 1 | 1] += lza[si];
		lza[si] = 0;
	}
}

void updatea(int si, int ss, int se, int a, int b, int x) {
	if (se < a || ss > b) return;
	if (ss >= a && se <= b) {
		seg[si] += 1LL * (se - ss + 1) * x, lza[si] += x;
		return;
	}
	push(si, ss, se);
	int mid = (ss + se) >> 1;
	updatea(si << 1, ss, mid, a, b, x), updatea(si << 1 | 1, mid + 1, se, a, b, x);
	seg[si] = seg[si << 1] + seg[si << 1 | 1];
}

void updates(int si, int ss, int se, int a, int b, int x) {
	if (se < a || ss > b) return;
	if (ss >= a && se <= b) {
		seg[si] = 1LL * (se - ss + 1) * x, lzs[si] = x, lza[si] = 0;
		return;
	}
	push(si, ss, se);
	int mid = (ss + se) >> 1;
	updates(si << 1, ss, mid, a, b, x), updates(si << 1 | 1, mid + 1, se, a, b, x);
	seg[si] = seg[si << 1] + seg[si << 1 | 1];
}

ll query(int si, int ss, int se, int a, int b) {
	if (se < a || ss > b) return 0;
	if (ss >= a && se <= b) return seg[si];
	push(si, ss, se);
	int mid = (ss + se) >> 1;
	return query(si << 1, ss, mid, a, b) + query(si << 1 | 1, mid + 1, se, a, b);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, op, a, b, x;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> t[i];
	build(1, 1, n);
	while (q--) {
		cin >> op >> a >> b;
		if (op == 1) cin >> x, updatea(1, 1, n, a, b, x);
		else if (op == 2) cin >> x, updates(1, 1, n, a, b, x);
		else cout << query(1, 1, n, a, b) << '\n';
	}
	return 0;
}