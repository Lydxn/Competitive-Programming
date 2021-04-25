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

vector<pii> adj[200001];
int deg[200001], dist0[200001], dist1[200001], dist2[200001];

void dfs(int *dist, int cur, int prev) {
	for (auto i : adj[cur])
		if (i.first != prev)
			dist[i.first] = dist[cur] + i.second, dfs(dist, i.first, cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, T, A, B, C, sum = 0;
	cin >> N >> T;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B >> C;
		adj[A].emplace_back(B, C), adj[B].emplace_back(A, C);
		++deg[A], ++deg[B], sum += C;
	}
	
	dfs(dist0, 1, -1);
	dfs(dist1, max_element(dist0 + 1, dist0 + N + 1) - dist0, -1);
	dfs(dist2, max_element(dist1 + 1, dist1 + N + 1) - dist1, -1);

	for (int i = 1; i <= N; i++)
		if (deg[i] == T) cout << i << ' ' << 2 * sum - max(dist1[i], dist2[i]) << '\n';
	return 0;
}
