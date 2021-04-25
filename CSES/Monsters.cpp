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

char g[1000][1000];
bool vis[1000][1000];
pii par[1000][1000], dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pii> q;
int dist[1000][1000], dist2[1000][1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	memset(dist, INF, sizeof(dist));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'M') q.emplace(i, j), dist[i][j] = 0;
		}
	}

	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();
		for (pii d : dir) {
			int nr = cr + d.first, nc = cc + d.second;
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] != '#' && dist[nr][nc] == INF)
				q.emplace(nr, nc), dist[nr][nc] = dist[cr][cc] + 1;
		}
	}

	memset(dist2, INF, sizeof(dist2));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == 'A') q.emplace(i, j), dist2[i][j] = 0;
			par[i][j] = {-1, -1};
		}
	}

	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();		
		for (pii d : dir) {
			int nr = cr + d.first, nc = cc + d.second;
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] != '#' && dist2[nr][nc] == INF && dist2[cr][cc] + 1 < dist[nr][nc])
				dist2[nr][nc] = dist2[cr][cc] + 1, par[nr][nc] = {cr, cc}, q.emplace(nr, nc);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!(i == 0 || i == n - 1 || j == 0 || j == m - 1) || dist2[i][j] == INF || g[i][j] == '#') continue;
			vector<pii> ans;
			for (; i != -1; tie(i, j) = par[i][j]) ans.emplace_back(i, j);
			cout << "YES\n" << ans.size() - 1 << '\n';
			
			reverse(ans.begin(), ans.end());
			for (int k = 1; k < int(ans.size()); k++) {
				int dr = ans[k].first - ans[k - 1].first, dc = ans[k].second - ans[k - 1].second;
				cout << (dc > 0 ? 'R' : dc < 0 ? 'L' : dr > 0 ? 'D' : 'U');
			}
			cout << '\n';
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
