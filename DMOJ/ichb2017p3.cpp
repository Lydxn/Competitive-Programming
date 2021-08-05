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

unsigned v[100001], seg[300001];

void build(int si, int ss, int se) {
	if (ss == se) { seg[si] = v[ss]; return; }
	int mid = (ss + se) >> 1;
	build(si << 1, ss, mid), build(si << 1 | 1, mid + 1, se);
	seg[si] = seg[si << 1] & seg[si << 1 | 1];
}

void update(int si, int ss, int se, int x, unsigned val) {
	if (ss > x || se < x) return;
	if (ss == se) { seg[si] = val; return; }
	int mid = (ss + se) >> 1;
	update(si << 1, ss, mid, x, val), update(si << 1 | 1, mid + 1, se, x, val);
	seg[si] = seg[si << 1] & seg[si << 1 | 1];
}

unsigned query(int si, int ss, int se, int x, int y) {
	if (ss > y || se < x) return -1U;
	if (ss >= x && se <= y) return seg[si];
	int mid = (ss + se) >> 1;
	return query(si << 1, ss, mid, x, y) & query(si << 1 | 1, mid + 1, se, x, y);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, y; unsigned val; char op;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> v[i];
	build(1, 1, N);
	while (Q--) {
		cin >> op;
		if (op == 'U') cin >> x >> val, update(1, 1, N, x, val);
		else cin >> x >> y >> val, cout << (query(1, 1, N, x, y) & val) << '\n';
	}
	return 0;
}
