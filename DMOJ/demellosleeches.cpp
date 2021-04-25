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

int S[200001], seg[600001], lazy[600001];

void push(int si, int s, int e) {
	if (lazy[si]) {
		seg[si] += lazy[si];
		if (s != e) lazy[si << 1] += lazy[si], lazy[si << 1 | 1] += lazy[si];
		lazy[si] = 0;
	}
}

void build(int si, int s, int e) {
	if (s == e) { seg[si] = S[s]; return; }
	int mid = (s + e) >> 1;
	build(si << 1, s, mid), build(si << 1 | 1, mid + 1, e);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

void update(int l, int r, int v, int si, int s, int e) {
	push(si, s, e);
	if (l > e || r < s) return;
	if (s >= l && e <= r) lazy[si] += v, push(si, s, e);
	else {
		int mid = (s + e) >> 1;
		update(l, r, v, si << 1, s, mid), update(l, r, v, si << 1 | 1, mid + 1, e);
		seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
	}
}

int walk(int si, int s, int e) {
	push(si, s, e);
	if (s == e) return s;
	int mid = (s + e) >> 1;
	if (seg[si << 1] + lazy[si << 1] < 0) return walk(si << 1, s, mid);
	if (seg[si << 1 | 1] + lazy[si << 1 | 1] < 0) return walk(si << 1 | 1, mid + 1, e);
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, Q, L, R;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> S[i];
	build(1, 0, n - 1);
	
	cin >> Q;
	while (Q--) {
		cin >> L >> R;
		update(L - 1, R - 1, -1, 1, 0, n - 1);

		int cnt = 0, idx;
		while ((idx = walk(1, 0, n - 1)) != -1)
			update(idx, idx, INF, 1, 0, n - 1), ++cnt;
		cout << cnt << '\n';
	}
	return 0;
}