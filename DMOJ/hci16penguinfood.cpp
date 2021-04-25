#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct data {
	int sum, pre, suf, ans;
	data() {}
	data(int sum, int pre, int suf, int ans) : sum(sum), pre(pre), suf(suf), ans(ans) {}
	data(int v) : sum(v), pre(max(0, v)), suf(max(0, v)), ans(max(0, v)) {}
};

template <const int MAXN, typename T>
struct SegTree
{
	T tree[2 * MAXN];
	const T DEFN = 0; // default node value?
	int _N;

	T merge(T& left, T& right) {
		return data(left.sum + right.sum, max(left.pre, left.sum + right.pre), max(right.suf, right.sum + left.suf), max(max(left.ans, right.ans), left.suf + right.pre));
	}

	void init(const auto& a, const int N = MAXN) {
		_N = N;
		for (int i = 0; i < _N; i++) tree[_N + i] = a[i];
		for (int i = _N - 1; i > 0; i--) tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
	}

	void init(const int N = MAXN) {
		_N = N;
	    for (int i = 0; i < _N; i++) tree[_N + i] = DEFN;
		for (int i = _N - 1; i > 0; i--) tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
	}

	void update(int i, const T v) {
		for (i += _N, tree[i] = v; i >>= 1; ) tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
	}

	T query(int l, int r) {
		T resl = DEFN, resr = DEFN;
		for (l += _N, r += _N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resl = merge(resl, tree[l++]);
			if (r & 1) resr = merge(tree[--r], resr);
		}
		return merge(resl, resr);
	}
};

const int MAXN = 1000000;
data A[MAXN];
SegTree<MAXN, data> segtree;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a, A[i] = a;
	segtree.init(A, N);

	cin >> M;
	while (M--) {
		cin >> x >> y;
		cout << segtree.query(0, N).ans << '\n';
		segtree.update(x, y);
	}
	cout << segtree.query(0, N).ans << '\n';
	return 0;
}
