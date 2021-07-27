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

vector<int> adj[2501];
queue<int> q;
int dst[2501];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b, ans = INF;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(dst, INF, sizeof(dst));
		q = {}; q.push(i); dst[i] = 0;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int j : adj[v]) {
				if (dst[j] == INF)
					dst[j] = dst[v] + 1, q.push(j);
				else if (dst[j] >= dst[v])
					{ ans = min(ans, dst[j] + dst[v] + 1); break; }
			}
		}
	}
	cout << (ans == INF ? -1 : ans) << '\n';
	return 0;
}
