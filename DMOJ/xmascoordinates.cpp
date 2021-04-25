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
int dist[1000][1000];
queue<pii> q;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, Pr = -1, Pc = -1, Or = -1, Oc = -1, Xr = -1, Xc = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'P') Pr = i, Pc = j;
			else if (grid[i][j] == 'O') Or = i, Oc = j;
			else if (grid[i][j] == 'X') Xr = i, Xc = j;
		}
	}

	memset(dist, -1, sizeof(dist));
	q.emplace(Pr, Pc); dist[Pr][Pc] = 0;
	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();
		for (auto d : dir) {
			int nr = cr + d.first, nc = cc + d.second;
			if (grid[nr][nc] != '#' && dist[nr][nc] == -1)
				dist[nr][nc] = dist[cr][cc] + 1, q.emplace(nr, nc);
		}
	}

	if (dist[Or][Oc] == -1 || dist[Xr][Xc] == -1) cout << "-1\n";
	else cout << dist[Or][Oc] + dist[Xr][Xc] << '\n';
	return 0;
}
