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

ll seg[600001], lazy[600001];

void push(int si, int s, int e) {
	if (lazy[si]) {
		seg[si << 1] += lazy[si], seg[si << 1 | 1] += lazy[si];
		lazy[si << 1] += lazy[si], lazy[si << 1 | 1] += lazy[si];
		lazy[si] = 0;
	}
}

void update(int si, int ss, int se, int l, int r, int v) {
	if (se < l || ss > r) return;
	if (ss >= l && se <= r) seg[si] += v, lazy[si] += v;
	else {
		push(si, ss, se);
		int mid = (ss + se) >> 1;
		update(si << 1, ss, mid, l, r, v), update(si << 1 | 1, mid + 1, se, l, r, v);
		seg[si] = max(seg[si << 1], seg[si << 1 | 1]);
	}
}

ll query(int si, int ss, int se, int l, int r) {
	if (se < l || ss > r) return 0;
	if (ss >= l && se <= r) return seg[si];
	push(si, ss, se);
	int mid = (ss + se) >> 1;
	return max(query(si << 1, ss, mid, l, r), query(si << 1 | 1, mid + 1, se, l, r));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, Q, op, L, R;
	cin >> N >> K >> Q;
	while (Q--) {
		cin >> op >> L >> R;
		if (op == 0) ++L, update(1, 1, N, max(1, L - K + 1), L, R);
		else ++L, ++R, cout << query(1, 1, N, L, min(R, N)) << '\n';
	}
	return 0;
}
