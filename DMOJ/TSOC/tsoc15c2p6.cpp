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

ll seg[3000001], lazy[3000001];
int R[1000001];

void push(int si) {
	if (lazy[si]) {
		seg[si << 1] += lazy[si], seg[si << 1 | 1] += lazy[si];
		lazy[si << 1] += lazy[si], lazy[si << 1 | 1] += lazy[si];
		lazy[si] = 0;
	}
}

void build(int si, int ss, int se) {
	if (ss == se) { seg[si] = R[ss]; return; }
	int mid = (ss + se) >> 1;
	build(si << 1, ss, mid), build(si << 1 | 1, mid + 1, se);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

void update(int si, int ss, int se, int a, int b, int c) {
	if (ss > b || se < a) return;
	if (ss >= a && se <= b) { seg[si] -= c, lazy[si] -= c; return; }
	push(si);
	int mid = (ss + se) >> 1;
	update(si << 1, ss, mid, a, b, c), update(si << 1 | 1, mid + 1, se, a, b, c);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

ll query(int si, int ss, int se, int a, int b) {
	if (ss > b || se < a) return INF;
	if (ss >= a && se <= b) return seg[si];
	push(si);
	int mid = (ss + se) >> 1;
	return min(query(si << 1, ss, mid, a, b), query(si << 1 | 1, mid + 1, se, a, b));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b, c;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> R[i];
	build(1, 1, N);
	while (Q--) {
		cin >> a >> b >> c;
		update(1, 1, N, a, b, c);
		cout << max(0LL, query(1, 1, N, a, b)) << ' ' << max(0LL, query(1, 1, N, 1, N)) << '\n';
	}
	return 0;
}
