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

vector<pii> adj[500001];
bool h[500001], in[500001];
int to[500001];
ll dst[500001], d0[500001], d1[500001], d2[500001], S;

void dfs1(int cur, int prev) {
	in[cur] = h[cur];
	for (auto i : adj[cur]) {
		if (i.first == prev) continue;
		dfs1(i.first, cur), in[cur] |= in[i.first];
		if (in[i.first]) S += i.second;
	}
}

void dfs2(int cur, int prev, int t) {
	to[cur] = t;
	for (auto i : adj[cur]) {
		if (i.first == prev) continue;
		if (!in[i.first]) dst[i.first] = dst[cur] + i.second;
		dfs2(i.first, cur, in[i.first] ? i.first : t);
	}
}

void dfs3(int cur, int prev, int &mi, ll *D) {
	if (D[cur] > D[mi]) mi = cur;
	for (auto i : adj[cur])
		if (i.first != prev && in[i.first])
			D[i.first] = D[cur] + i.second, dfs3(i.first, cur, mi, D);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, A, B, C, k;
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B >> C;
		adj[A].emplace_back(B, C), adj[B].emplace_back(A, C);
	}
	int st = -1;
	while (K--) cin >> k, h[k] = true, st = k;
	dfs1(st, 0); dfs2(st, 0, st);
	dfs3(st, 0, st, d0); dfs3(st, 0, st, d1); dfs3(st, 0, st, d2);
	for (int i = 1; i <= N; i++) cout << 2 * S + dst[i] - max(d1[to[i]], d2[to[i]]) << '\n';
	return 0;
}
