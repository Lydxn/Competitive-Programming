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

int seg[800001];

void update(int i, int v, int sl, int sr, int si) {
	if (i < sl || sr < i) return;
	if (sl == sr) seg[si] = v;
	else {
		int mid = (sl + sr) >> 1;
		update(i, v, sl, mid, si << 1), update(i, v, mid + 1, sr, si << 1 | 1);
		seg[si] = min(seg[si << 1], seg[si << 1 | 1]);
	}
}

int query(int l, int r, int sl, int sr, int si) {
	if (sl > r || sr < l) return INF;
	if (l <= sl && sr <= r) return seg[si];
	int mid = (sl + sr) >> 1;
	return min(query(l, r, sl, mid, si << 1), query(l, r, mid + 1, sr, si << 1 | 1));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, X, Y; char op;
	cin >> N >> Q;
	memset(seg, 0x3f, sizeof(seg));
	while (Q--) {
		cin >> op >> X >> Y;
		if (op == 'M') update(Y, X, 1, N, 1);
		else {
			int l = Y, r = N, mid;
			while (l <= r) {
				mid = (l + r) >> 1;
				if (query(l, mid, 1, N, 1) <= X) r = mid - 1;
				else l = mid + 1;
			}
			cout << (l == N + 1 ? -1 : l) << '\n';
		}
	}
	return 0;
}
