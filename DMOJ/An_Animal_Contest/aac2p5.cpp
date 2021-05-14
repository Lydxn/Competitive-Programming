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

template <const int MAXN, typename T, const int INDEXING>
struct SparseTable {
	T sparse[32 - __builtin_clz(MAXN)][MAXN]; int lg[MAXN + 1], N;
	T query_op(T a, T b) { return max(a, b); }
	template <typename It> void init(It st, It en) {
		N = en - st; std::copy(st, en, sparse[0]);
		lg[1] = 0; for (int i = 2; i <= N; i++) lg[i] = lg[i >> 1] + 1;
		for (int j = 0; j < lg[N]; j++)
			for (int i = 0; i + (1 << j) < N; i++)
				sparse[j + 1][i] = query_op(sparse[j][i], sparse[j][i + (1 << j)]);
	}
	T query(int l, int r) { l -= INDEXING, r -= INDEXING; int k = lg[r - l + 1]; return query_op(sparse[k][l], sparse[k][r - (1 << k) + 1]); }
};

int a[1000001], len[1000001], idx[1000001], cnt[1000001];
SparseTable<1000000, int, 1> st;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, l, r;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int cl = 1, cr = 0, sz = 0; cl <= N; cl++) {
		while (cr + 1 <= N && !cnt[a[cr + 1]]) ++cnt[a[++cr]], ++sz;
		len[cl] = cr - cl + 1, idx[cl] = cr;
		sz -= !--cnt[a[cl]];
	}
	st.init(len + 1, len + N + 1);
	int lastAns = 0;
	while (Q--) {
		cin >> l >> r; l ^= lastAns, r ^= lastAns;
		cout << (lastAns = st.query(lower_bound(idx + 1, idx + l + 1, r) - idx, l)) << '\n';
	}
	return 0;
}