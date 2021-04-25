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

template <const int MAXN, typename TV, typename TQ, const int INDEXING>
struct SegTree {
	TQ tree[MAXN << 1]; int N; const TQ DEFV = 0, DEFQ = 0; // default value of array and queries
	TQ query_op(TQ a, TQ b) { return max(a, b); }
	TQ update_op(TQ a, TV b) { return b; }
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

pii x[100001], y[100001];
int dp[100001];
SegTree<100000, int, int, 1> seg;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, b;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a >> b, x[i] = {a, b};
	sort(x + 1, x + N + 1);
	for (int i = 1; i <= N; i++) y[i] = {x[i].first + x[i].second, i};
	sort(y + 1, y + N + 1);
	
	seg.init();
	for (int i = 1, idx = 0; i <= N; i++) {
		while (idx < N && y[idx + 1].first <= x[i].first)
			++idx, seg.update(y[idx].second, dp[y[idx].second]);
		int r = upper_bound(x + 1, x + N + 1, make_pair(x[i].first - x[i].second, INF)) - x - 1;
		dp[i] = r > 0 ? seg.query(1, r) + 1 : 1;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) ans = max(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}
