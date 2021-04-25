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

char grid[100][100];
queue<pii> q;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dist[100][100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, R, C;
	cin >> M;
	while (M--) {
		cin >> R >> C;
		int sr = -1, sc = -1;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'C') sr = i, sc = j;
			}
		}

		q = {}; q.emplace(sr, sc);
		memset(dist, -1, sizeof(dist)); dist[sr][sc] = 0;
		while (!q.empty()) {
			int cr = q.front().first, cc = q.front().second; q.pop();
			for (auto d : dir) {
				int nr = cr + d.first, nc = cc + d.second;
				if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != '#' && dist[nr][nc] == -1)
					q.emplace(nr, nc), dist[nr][nc] = dist[cr][cc] + 1;
			}
		}

		int ans = 0, mx = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				if (grid[i][j] == 'S')
					ans += 2 * dist[i][j] + 60, mx = max(mx, dist[i][j]);
		cout << ans - mx << '\n';
	}
	return 0;
}
