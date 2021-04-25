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

vector<int> adj[30001];
queue<int> q;
int dist[30001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, a, b, k, ans = 0;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}

	cin >> K;
	memset(dist, -1, sizeof(dist));
	while (K--) cin >> k, dist[k] = 0, q.push(k);

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int i : adj[v])
			if (dist[i] == -1)
				ans = max(ans, dist[i] = dist[v] + 1), q.push(i);
	}
	cout << ans << '\n';
	return 0;
}
