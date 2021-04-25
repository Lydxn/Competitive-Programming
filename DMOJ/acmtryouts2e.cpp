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

char grid[1000][1000];
int pr[2], pc[2], pdist[2][1000][1000], dist[1000][1000];
queue<pii> q;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int G, H, W;
	cin >> G;
	while (G--) {
		cin >> H >> W;
		int sr = -1, sc = -1, er = -1, ec = -1, pidx = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'P') sr = i, sc = j;
				else if (grid[i][j] == 'C') er = i, ec = j;
				else if (grid[i][j] == 'M') pr[pidx] = i, pc[pidx] = j, pidx++;
			}
		}

		memset(pdist, -1, sizeof(pdist));
		for (int i = 0; i < 2; i++) {
			q = {}; q.emplace(pr[i], pc[i]);
			pdist[i][pr[i]][pc[i]] = 0;
			while (!q.empty()) {
				int cr = q.front().first, cc = q.front().second; q.pop();
				for (auto d : dir) {
					int nr = cr + d.first, nc = cc + d.second;
					if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] != 'W' && grid[nr][nc] != 'M' && pdist[i][nr][nc] == -1)
						q.emplace(nr, nc), pdist[i][nr][nc] = pdist[i][cr][cc] + 1;
				}
			}
		}

		memset(dist, -1, sizeof(dist)); dist[sr][sc] = 0;
		q = {}; q.emplace(sr, sc);
		while (!q.empty()) {
			int cr = q.front().first, cc = q.front().second; q.pop();
			if (cr == er && cc == ec) {
				cout << "pwned you in " << dist[cr][cc] << " seconds eZ, learn to play n00b\n";
				goto done;
			}

			for (auto d : dir) {
				int nr = cr + d.first, nc = cc + d.second;
				if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] != 'W' && grid[nr][nc] != 'M' && dist[nr][nc] == -1) {
					if (grid[cr][cc] == 'U' || grid[nr][nc] == 'U') {
						bool good = false;
						for (int i = 0; i < 2; i++) good |= pdist[i][nr][nc] < pdist[i][cr][cc];
						if (!good) continue;
					}
					q.emplace(nr, nc), dist[nr][nc] = dist[cr][cc] + 1;
				}
			}
		}
		cout << "terran so broken, apologize for playing this race\n"; done:;
	}
	return 0;
}
