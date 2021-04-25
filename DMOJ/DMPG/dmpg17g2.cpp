#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct data {
	ll sum, l, r, ans;
	bool empty;
};

template <const int MAXN, typename TV, typename TQ, const int INDEXING>
struct SegTree {
	TQ tree[MAXN << 1]; int N; const TQ DEFV = {0, 0, 0, 0}, DEFQ = {0, 0, 0, INT_MIN};
	TQ query_op(TQ a, TQ b) {
		return {a.sum + b.sum, max(a.l, a.sum + b.l), max(b.r, b.sum + a.r), max(max(a.ans, b.ans), a.r + b.l)};
	}
	TQ update_op(TQ a, TV b) {
		return {b, b, b, b};
	}
	void init(int N = MAXN) {
		this->N = N; for (int i = 0; i < N; i++) tree[N + i] = DEFV;
		for (int i = N - 1; i; i--) tree[i] = query_op(tree[i << 1], tree[i << 1 | 1]);
	}
	template <typename It> void init(It st, It en) {
		N = en - st; for (int i = 0; i < N; i++) tree[N + i] = *(st + i);
		for (int i = N - 1; i; i--) tree[i] = query_op(tree[i << 1], tree[i << 1 | 1]);
	}
	void update(int i, TV v) { for (i += N - INDEXING, tree[i] = update_op(tree[i], v); i >>= 1; ) tree[i] = query_op(tree[i << 1], tree[i << 1 | 1]); }
	TQ query(int l, int r) {
		TQ resl = DEFQ, resr = DEFQ;
		for (l += N - INDEXING, r += N - INDEXING; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) resl = query_op(resl, tree[l++]);
			if (!(r & 1)) resr = query_op(tree[r--], resr);
		}
		return query_op(resl, resr);
	}
};

SegTree<100000, int, data, 1> segtree;
data d[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b; char op;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> d[i].ans, d[i].l = d[i].r = d[i].sum = d[i].ans;

	segtree.init(d, d + N);
	while (Q--) {
		cin >> op >> a >> b;
		if (op == 'S') segtree.update(a, b);
		else cout << segtree.query(a, b).ans << '\n';
	}
	return 0;
}
