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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'A') q.emplace(i, j), vis[i][j] = true;
			par[i][j] = {-1, -1};
		}
	}

	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();
		if (g[cr][cc] == 'B') {
			vector<pii> ans;
			for (; cr != -1; tie(cr, cc) = par[cr][cc]) ans.emplace_back(cr, cc);
			cout << "YES\n" << ans.size() - 1 << '\n';
			
			reverse(ans.begin(), ans.end());
			for (int i = 1; i < int(ans.size()); i++) {
				int dr = ans[i].first - ans[i - 1].first, dc = ans[i].second - ans[i - 1].second;
				cout << (dc > 0 ? 'R' : dc < 0 ? 'L' : dr > 0 ? 'D' : 'U');
			}
			cout << '\n';
			return 0;
		}
		
		for (pii d : dir) {
			int nr = cr + d.first, nc = cc + d.second;
			if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] != '#' && !vis[nr][nc])
				vis[nr][nc] = true, par[nr][nc] = {cr, cc}, q.emplace(nr, nc);
		}
	}
	cout << "NO\n";
	return 0;
}
