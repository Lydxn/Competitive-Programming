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

int a[100000], seg[400001];

void build(int i, int s, int e) {
	if (s == e) seg[i] = a[s];
	else {
		int mid = (s + e) >> 1;
		build(i << 1, s, mid), build(i << 1 | 1, mid + 1, e);
		seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
	}
}

void update(int i, int s, int e, int pos, int v) {
	if (s == e) seg[i] = v;
	else {
		int mid = (s + e) >> 1;
		if (pos <= mid) update(i << 1, s, mid, pos, v);
		else update(i << 1 | 1, mid + 1, e, pos, v);
		seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
	}
}

int query(int i, int s, int e, int l, int r) {
	if (l > e || r < s) return INF;
	if (l <= s && r >= e) return seg[i];
	int mid = (s + e) >> 1;
	return min(query(i << 1, s, mid, l, r), query(i << 1 | 1, mid + 1, e, l, r));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, x, y; char op;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> a[i];

	build(1, 0, N - 1);
	while (M--) {
		cin >> op >> x >> y;
		if (op == 'M') update(1, 0, N - 1, x, y);
		else cout << query(1, 0, N - 1, x, y) << '\n';
	}
	return 0;
}
