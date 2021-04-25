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

vector<int> adj[200001];
queue<int> q;
int dist[200001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, M, x;
	cin >> N >> K >> M;
	for (int i = 1; i <= M; i++)
		for (int j = 0; j < K; j++)
			cin >> x, adj[x].push_back(N + i), adj[N + i].push_back(x);

	memset(dist, -1, sizeof(dist));
	dist[1] = 0, q.push(1);
	while (!q.empty()) {
		int cv = q.front(); q.pop();
		if (cv == N) { cout << dist[cv] / 2 + 1 << '\n'; return 0; }
		for (int i : adj[cv])
			if (dist[i] == -1)
				q.push(i), dist[i] = dist[cv] + 1;
	}
	cout << "-1\n";
	return 0;
}
