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

int N, seg[600001], lazy[600001], bit[200001];

void bupdate(int i) { for (; i <= N; i += i & -i) ++bit[i]; }
int bquery(int i) { int res = 0; for (; i; i -= i & -i) res += bit[i]; return res; }

void push(int si, int ss, int se) {
	if (lazy[si]) {
		seg[si << 1] += lazy[si], seg[si << 1 | 1] += lazy[si];
		lazy[si << 1] += lazy[si], lazy[si << 1 | 1] += lazy[si];
		lazy[si] = 0;
	}
}

void build(int si, int ss, int se) {
	if (ss == se) { seg[si] = ss; return; }
	int mid = (ss + se) >> 1;
	build(si << 1, ss, mid), build(si << 1 | 1, mid + 1, se);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

void update(int si, int ss, int se, int l, int r, int v) {
	if (ss > r || se < l) return;
	if (ss >= l && se <= r) { seg[si] += v, lazy[si] += v; return; }
	push(si, ss, se);
	int mid = (ss + se) >> 1;
	update(si << 1, ss, mid, l, r, v), update(si << 1 | 1, mid + 1, se, l, r, v);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

int walk(int si, int ss, int se) {
	if (ss == se) return ss;
	push(si, ss, se);
	int mid = (ss + se) >> 1;
	if (seg[si << 1] == 0) return walk(si << 1, ss, mid);
	if (seg[si << 1 | 1] == 0) return walk(si << 1 | 1, mid + 1, se);
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q, t, l, r;
	cin >> N >> Q; N = min(N, Q);
	build(1, 1, N);
	while (Q--) {
		cin >> t >> l >> r;
		if (l > N) continue;
		if (t == 1) {
			update(1, 1, N, l, min(r, N), -1);
			int idx;
			while ((idx = walk(1, 1, N)) != -1)
				update(1, 1, N, idx, idx, idx), bupdate(idx);
		} else cout << bquery(min(r, N)) - bquery(l - 1) << '\n';
	}
	return 0;
}
