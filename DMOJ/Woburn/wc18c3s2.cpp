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

bool g[100001], gg[100001];
vector<int> adj[100001];
int dep[100001], fdep[100001], tot;

bool dfs(int cur, int prev) {
	bool gym = g[cur];
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dep[i] = dep[cur] + 1;
		if (dfs(i, cur)) gym = true, ++tot;
	}
	return gg[cur] = gym;
}

void dfs2(int cur, int prev) {
	for (int i : adj[cur])
		if (i != prev) fdep[i] = fdep[cur] + !gg[i], dfs2(i, cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, F, A, B, G;
	cin >> N >> K >> F;
	while (K--) cin >> G, g[G] = true;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		adj[A].push_back(B), adj[B].push_back(A);
	}
	
	dfs(1, -1), dfs2(1, -1);
	int mx = 0;
	for (int i = 1; i <= N; i++)
		if (g[i]) mx = max(mx, dep[i]);
	cout << min(2 * tot - mx, tot + fdep[F]) << '\n';
	return 0;
}
