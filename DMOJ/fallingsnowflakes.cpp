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

struct qu {
	int type, idx, a, b, c, d, t;
	bool operator< (qu &q) const {
		return t < q.t || (t == q.t && type < q.type);
	}
} q[300000];
int BIT[5001][5001], ans[100000], N, qidx;

void update(int r, int c, int x) {
	for (int i = r; i <= N; i += i & -i)
		for (int j = c; j <= N; j += j & -j)
			BIT[i][j] += x;
}

int query(int r, int c) {
	int res = 0;
	for (int i = r; i; i -= i & -i)
		for (int j = c; j; j -= j & -j)
			res += BIT[i][j];
	return res;
}

int query(int r0, int r1, int c0, int c1) {
	return query(r1, c1) - query(r0 - 1, c1) - query(r1, c0 - 1) + query(r0 - 1, c0 - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, Q, R, C, L, D, a, b, c, d, t; char op;
	cin >> N >> M >> Q;
	while (M--) {
		cin >> R >> C >> L >> D;
		q[qidx++] = {0, -1, R, C, -1, -1, L}, q[qidx++] = {1, -1, R, C, -1, -1, D};
	}

	for (int i = 0; i < Q; i++) {
		cin >> op;
		if (op == 'R') cin >> a >> b >> t, q[qidx++] = {2, i, a, b, -1, -1, t};
		else if (op == 'C') cin >> a >> b >> t, q[qidx++] = {3, i, a, b, -1, -1, t};
		else cin >> a >> b >> c >> d >> t, q[qidx++] = {4, i, a, b, c, d, t};
	}

	sort(q, q + qidx);
	for (int i = 0; i < qidx; i++) {
		if (q[i].type == 0) update(q[i].a, q[i].b, 1);
		else if (q[i].type == 1) update(q[i].a, q[i].b, -1);
		else if (q[i].type == 2) ans[q[i].idx] = query(q[i].a, q[i].b, 1, N);
		else if (q[i].type == 3) ans[q[i].idx] = query(1, N, q[i].a, q[i].b);
		else ans[q[i].idx] = query(q[i].a, q[i].b, 1, N) + query(1, N, q[i].c, q[i].d) - query(q[i].a, q[i].b, q[i].c, q[i].d);
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
	return 0;
}
