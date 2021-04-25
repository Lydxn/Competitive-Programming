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

char grid[10][10];
int dist[10][10];
pii dir[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);

	int br = -1, bc = -1;
	queue<pii> q;
	memset(dist, -1, sizeof(dist));
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'B') br = i, bc = j;
			if (grid[i][j] == 'L') q.emplace(i, j), dist[i][j] = 0;
		}
	}

	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();
		if (cr == br && cc == bc) { cout << dist[cr][cc] - 1 << '\n'; return 0; }
		for (auto d : dir) {
			int nr = cr + d.first, nc = cc + d.second;
			if (nr >= 0 && nr < 10 && nc >= 0 && nc < 10 && dist[nr][nc] == -1 && grid[nr][nc] != 'R')
				dist[nr][nc] = dist[cr][cc] + 1, q.emplace(nr, nc);
		}
	}
	return 0;
}
