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

vector<int> b[500001], s[500001], e[500001];
int idx[500001], sz[1000001], par[1000001];

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
void join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u, sz[u] += sz[v];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, Q, r, c, ra, ca, rb, cb;
	cin >> N >> M >> K >> Q;
	while (K--) cin >> r >> c, b[r].push_back(c);
	
	for (int i = 1; i <= N; i++) {
		b[i].push_back(0), b[i].push_back(M + 1);
		sort(b[i].begin(), b[i].end());
	}

	idx[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < int(b[i].size()); j++) {
			int bs = b[i][j - 1] + 1, be = b[i][j] - 1;
			if (bs <= be) s[i].push_back(bs), e[i].push_back(be);
		}
		idx[i] = idx[i - 1] + s[i].size();
	}

	for (int i = 1; i <= idx[N]; i++) par[i] = i, sz[i] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < int(s[i + 1].size()); j++) {
			int bs = s[i + 1][j], be = e[i + 1][j];
			int rl = lower_bound(e[i].begin(), e[i].end(), bs) - e[i].begin();
			int rr = upper_bound(s[i].begin(), s[i].end(), be) - s[i].begin() - 1;
			for (int k = rl; k <= rr; k++) join(idx[i - 1] + k, idx[i] + j);
		}
	}

	while (Q--) {
		cin >> ra >> ca >> rb >> cb;
		int aidx = idx[ra - 1] + lower_bound(e[ra].begin(), e[ra].end(), ca) - e[ra].begin();
		int bidx = idx[rb - 1] + lower_bound(e[rb].begin(), e[rb].end(), cb) - e[rb].begin();
		cout << (find(aidx) == find(bidx) ? "YES" : "NO") << '\n';
	}
	return 0;
}
