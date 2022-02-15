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

template <const int MAXV, const int INDEXING>
struct BFS {
	std::vector<int> adj[MAXV + INDEXING]; std::queue<int> q; int dist[MAXV + INDEXING], par[MAXV + INDEXING], V;
	void add(int u, int v) { adj[u].push_back(v); }
	void add_bi(int u, int v) { add(u, v); add(v, u); }
	void min_path(int v, int V = MAXV) {
		this->V = V; q = {}; std::fill(dist, dist + V + INDEXING, INT_MAX); std::fill(par, par + V + INDEXING, -1);
		q.push(v); dist[v] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int i : adj[cur]) if (dist[i] == INT_MAX) dist[i] = dist[cur] + 1, par[i] = cur, q.push(i);
		}
	}
	std::vector<int> get_path(int v) {
		std::vector<int> res;
		for (; v != -1; v = par[v]) res.push_back(v);
		std::reverse(res.begin(), res.end()); return res;
	}
	void clear() { for (int i = 0; i < V + INDEXING; i++) adj[i].clear(); }
};

BFS<40000, 1> bfs;
char g[200][200];
int loc[5], lc[26];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> g[i][j];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (isdigit(g[i][j])) loc[g[i][j] - '0'] = i * C + j;
			if ('a' <= g[i][j] && g[i][j] <= 'z') lc[g[i][j] - 'a'] = i * C + j;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (auto [r, c] : dir) {
				int nr = i + r, nc = j + c;
				if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if ('a' <= g[nr][nc] && g[nr][nc] <= 'z') continue;
				if (g[i][j] == '#' || g[nr][nc] == '#') continue;
				bfs.add(i * C + j, isalpha(g[nr][nc]) ? lc[g[nr][nc] - 'A'] : nr * C + nc);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		bfs.min_path(loc[i]);
		if (bfs.dist[loc[i + 1]] == INT_MAX) { cout << "-1\n"; return 0; }
		ans += bfs.dist[loc[i + 1]];
	}
	cout << ans << '\n';
	return 0;
}