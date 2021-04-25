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

// plz no TLE
char _i[1 << 25], _o[1 << 23], _, __[10]; int _i0, _o0;
#define scanu(x) { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); }
#define putnumu(x) { _ = 0; do __[_++] = x % 10 | '0'; while (x /= 10); while (_--) _o[_o0++] = __[_]; }

int a[1000001], seg[3000001];

void build(int si, int ss, int se) {
	if (ss == se) { seg[si] = a[ss]; return; }
	int mid = (ss + se) >> 1;
	build(si << 1, ss, mid), build(si << 1 | 1, mid + 1, se);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

void update(int si, int ss, int se, int p, int x) {
	if (se < p || ss > p) return;
	if (ss == se) { seg[si] = x; return; }
	int mid = (ss + se) >> 1;
	update(si << 1, ss, mid, p, x), update(si << 1 | 1, mid + 1, se, p, x);
	seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
}

int query(int si, int ss, int se, int l, int r, int k) {
	if (se < l || ss > r) return INF;
	if (ss >= l && se <= r) {
		if (seg[si] >= k) return INF;
		while (ss < se) {
			int mid = (ss + se) >> 1;
			if (seg[si << 1] < k) si <<= 1, se = mid;
			else si = si << 1 | 1, ss = mid + 1;
		}
		return ss;
	}
	int mid = (ss + se) >> 1;
	int res = query(si << 1, ss, mid, l, r, k);
	if (res != INF) return res;
	return query(si << 1 | 1, mid + 1, se, l, r, k);
}

int main() {
	fread(_i, 1, 1 << 25, stdin);
	int N, Q, op, p, x, l, r, k, X = 0;
	scanu(N); scanu(Q);
	for (int i = 1; i <= N; i++) scanu(a[i]);
	memset(seg, INF, sizeof(seg)); build(1, 1, N);
	while (Q--) {
		scanu(op);
		if (op == 1) { scanu(p); scanu(x); update(1, 1, N, p ^ X, x ^ X); }
		else {
			scanu(l); scanu(r); scanu(k); X = query(1, 1, N, l ^ X, r ^ X, k ^ X);
			int ans = X; putnumu(ans); _o[_o0++] = '\n';
		}
	}
	fwrite(_o, 1, _o0, stdout);
	return 0;
}
