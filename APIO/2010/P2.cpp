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

unordered_set<ll> uset;
vector<int> adj[100001];
int par[100001];

void dfs1(int cur, int prev, int dep, int &mxd, int &mxi) {
	par[cur] = prev;
	if (dep > mxd) mxd = dep, mxi = cur;
	for (int i : adj[cur])
		if (i != prev)
			dfs1(i, cur, dep + 1, mxd, mxi);
}

int dfs2(int cur, int prev, int &mxd) {
	int mx1 = 0, mx2 = 0;
	for (int i : adj[cur]) {
		if (i != prev) {
			int h = dfs2(i, cur, mxd) + (uset.count((ll) cur << 20 | i) ? -1 : 1);
			if (h >= mx1) mx2 = mx1, mx1 = h;
			else if (h > mx2) mx2 = h;
		}
	}
	mxd = max(mxd, mx1 + mx2);
	return mx1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, A, B;
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		adj[A].push_back(B), adj[B].push_back(A);
	}

	int mxd = 0, mxi = -1;
	dfs1(1, -1, 0, mxd, mxi);
	memset(par, 0, sizeof(par));
	dfs1(mxi, -1, 0, mxd = 0, mxi);

	if (K == 1) cout << 2 * (N - 1) - mxd + 1 << '\n';
	else {
		while (mxi != -1) {
			uset.insert((ll) mxi << 20 | par[mxi]), uset.insert((ll) par[mxi] << 20 | mxi);
			mxi = par[mxi];
		}

		int mxd2 = 0;
		dfs2(1, -1, mxd2);
		cout << 2 * (N - 1) - mxd - mxd2 + 2 << '\n';
	}
	return 0;
}
