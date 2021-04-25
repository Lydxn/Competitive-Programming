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

ll x[200001], seg[600001], l[600001], r[600001], s[600001];

void merge(int si) {
	s[si] = s[si << 1] + s[si << 1 | 1];
	l[si] = max(l[si << 1], s[si << 1] + l[si << 1 | 1]);
	r[si] = max(r[si << 1 | 1], r[si << 1] + s[si << 1 | 1]);
	seg[si] = max(max(seg[si << 1], seg[si << 1 | 1]), r[si << 1] + l[si << 1 | 1]);
}

void build(int si, int ss, int se) {
	if (ss == se) { seg[si] = l[si] = r[si] = s[si] = x[ss]; return; }
	int mid = (ss + se) >> 1;
	build(si << 1, ss, mid), build(si << 1 | 1, mid + 1, se);
	merge(si);
}

void update(int si, int ss, int se, int a, int b) {
	if (se < a || ss > a) return;
	if (ss == se) { seg[si] = l[si] = r[si] = s[si] = b; return; }
	int mid = (ss + se) >> 1;
	update(si << 1, ss, mid, a, b), update(si << 1 | 1, mid + 1, se, a, b);
	merge(si);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x[i];
	build(1, 1, n);
	while (m--) {
		cin >> a >> b;
		update(1, 1, n, a, b);
		cout << max(0LL, seg[1]) << '\n';
	}
	return 0;
}
