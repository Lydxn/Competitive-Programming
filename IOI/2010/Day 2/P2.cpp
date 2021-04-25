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

vector<int> adj[1000000];
int *pp, tot, ans = INF, idx;

int dfs(int cur, int prev) {
	int res = pp[cur], mx = 0;
	for (int i : adj[cur]) {
		if (i == prev) continue;
		int s = dfs(i, cur);
		res += s, mx = max(mx, s);
	}
	mx = max(mx, tot - res);
	if (mx < ans) ans = mx, idx = cur;
	return res;
}

int LocateCentre(int N, int P[], int S[], int D[]) {
	for (int i = 0; i < N; i++) tot += P[i];
	for (int i = 0; i < N - 1; i++) adj[S[i]].push_back(D[i]), adj[D[i]].push_back(S[i]);
	pp = P, dfs(0, -1);
	return idx;
}
