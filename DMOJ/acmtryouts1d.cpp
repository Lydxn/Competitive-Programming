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

char grid[6][6];
queue<int> q;
int R[50][50], par[50], H, W;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool bfs(int src, int sink) {
	q = {}; q.push(src);
	memset(par, -1, sizeof(par)); par[src] = -2;

	while (!q.empty()) {
		int cv = q.front(); q.pop();
		for (int i = 0; i < 50; i++) {
			if (R[cv][i] > 0 && par[i] == -1) {
				par[i] = cv;
				if (i == sink) return true;
				q.push(i);
			}
		}
	}
	return false;
}

int maxflow(int src, int sink) {
	int res = 0;
	while (bfs(src, sink)) {
		int cur = INF;
		for (int i = sink; i != src; i = par[i])
			cur = min(cur, R[par[i]][i]);
		for (int i = sink; i != src; i = par[i])
			R[par[i]][i] -= cur, R[i][par[i]] += cur;
		res += cur;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, src = -1, sink = -1;
	cin >> T;
	while (T--) {
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'F') src = i * 7 + j;
				if (grid[i][j] == 'H') sink = i * 7 + j;
			}
		}

		memset(R, 0, sizeof(R));
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (grid[i][j] == 'T') continue;
				for (auto d : dir) {
					int r = i + d.first, c = j + d.second;
					if (r >= 0 && r < H && c >= 0 && c < W && grid[r][c] != 'T')
						R[i * 7 + j][r * 7 + c] = 1;
				}
			}
		}
		cout << maxflow(src, sink) << '\n';
	}
	return 0;
}
