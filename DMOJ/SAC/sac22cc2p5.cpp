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
struct BIT {
	T bit[MAXN + 1]; int N, lg;
	void init(int N = MAXN) { this->N = N; std::fill(bit, bit + N + 1, 0); lg = 31 - __builtin_clz(N + 1); }
	template <typename It> void init(It st, It en) {
		N = en - st; std::fill(bit, bit + N + 1, 0); lg = 31 - __builtin_clz(N + 1);
		for (int i = 1; i <= N; i++) {
			bit[i] += *(st + i - 1);
			int idx = i + (i & -i); if (idx <= N) bit[idx] += bit[i];
		}
	}
	void update(int i, T x) { for (i += 1 - INDEXING; i <= N; i += i & -i) bit[i] += x; }
	T query(int i) { T res = 0; for (i += 1 - INDEXING; i; i -= i & -i) res += bit[i]; return res; }
	T query(int l, int r) { return query(r) - query(l - 1); }
	int lower_bound(T x) {
	    int res = 0; T sum = 0;
	    for (int i = lg; i >= 0; i--) {
	        int nxt = res | (1 << i);
	        if (nxt <= N && sum + bit[nxt] < x) res = nxt, sum += bit[nxt];
	    }
	    return res + INDEXING;
	}
	int upper_bound(T x) {
	    int res = 0; T sum = 0;
	    for (int i = lg; i >= 0; i--) {
	        int nxt = res | (1 << i);
	        if (nxt <= N && sum + bit[nxt] < x) res = nxt, sum += bit[nxt];
	    }
	    return res + INDEXING;
	}
};

BIT<1000000, ll, 1> b[2];
int A[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;
	b[0].init(N), b[1].init(N);
	for (int i = 1; i <= N; i++) cin >> A[i], b[i % 2].update(i, A[i]);
	while (Q--) {
		int op, x, y; cin >> op >> x >> y;
		if (op == 1) b[x % 2].update(x, y - A[x]), A[x] = y;
		else cout << b[x % 2].query(x, y) << '\n';
	}
	return 0;
}
