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

int seg[3000001];
bool lazy[3000001];

void build(int si, int s, int e) {
	if (s == e) { seg[si] = 1; return; }
	int mid = (s + e) >> 1;
	build(si << 1, s, mid), build(si << 1 | 1, mid + 1, e);
	seg[si] = seg[si << 1] + seg[si << 1 | 1];
}

void push(int si, int s, int e) {
	if (lazy[si]) {
		int mid = (s + e) >> 1;
		seg[si << 1] = mid - s + 1 - seg[si << 1], seg[si << 1 | 1] = e - mid - seg[si << 1 | 1];
		lazy[si << 1] ^= lazy[si], lazy[si << 1 | 1] ^= lazy[si];
		lazy[si] = false;
	}
}

void update(int l, int r, int si, int s, int e) {
	if (e < l || s > r) return;
	if (l <= s && e <= r) lazy[si] ^= true, seg[si] = e - s + 1 - seg[si];
	else {
		push(si, s, e);
		int mid = (s + e) >> 1;
		update(l, r, si << 1, s, mid), update(l, r, si << 1 | 1, mid + 1, e);
		seg[si] = seg[si << 1] + seg[si << 1 | 1];
	}
}

int query(int si, int s, int e, int L) {
	if (s == e) return s;
	push(si, s, e);
	int mid = (s + e) >> 1;
	if (seg[si << 1] >= L) return query(si << 1, s, mid, L);
	else return query(si << 1 | 1, mid + 1, e, L - seg[si << 1]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, L, a, b;
	cin >> N >> M >> L;
	build(1, 1, N);
	
	while (M--) {
		cin >> a >> b;
		update(a, b, 1, 1, N);
		if (seg[1] < L) cout << "AC?\n";
		else cout << query(1, 1, N, L) << '\n';
	}
	return 0;
}
