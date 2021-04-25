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

char grid[4000][4000];
bool vis[4000][4000];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pii> q1, q2;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> grid[i][j];

	int ans = 0;
	vis[0][0] = true; q1.emplace(0, 0);
	while (!q1.empty()) {
		while (!q1.empty()) {
			int cr = q1.front().first, cc = q1.front().second; q1.pop();
			for (auto d : dir) {
				int nr = cr + d.first, nc = cc + d.second;
				if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] != '.' && !vis[nr][nc])
					vis[nr][nc] = true, (grid[cr][cc] == grid[nr][nc] ? q1 : q2).emplace(nr, nc);
			}
		}
		swap(q1, q2), ++ans;
	}
	cout << ans << '\n';
	return 0;
}
