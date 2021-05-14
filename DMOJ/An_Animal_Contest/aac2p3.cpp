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

char g[1501][1501];
int N, M, psa[1501][1501];
queue<pii> q;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool vis[1501][1501];

bool check(int r, int c, int x) {
	return psa[r + x - 1][c + x - 1] - psa[r - 1][c + x - 1] - psa[r + x - 1][c - 1] + psa[r - 1][c - 1] == 0;
}

bool f(int x) {
	if (!check(1, 1, x)) return false;
	memset(vis, false, sizeof(vis));
	q.emplace(1, 1); vis[1][1] = true;
	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();
		for (pii d : dir) {
			int nr = cr + d.first, nc = cc + d.second;
			if (nr > 0 && nc > 0 && nr + x - 1 <= N && nc + x - 1 <= M && !vis[nr][nc] && check(nr, nc, x))
				q.emplace(nr, nc), vis[nr][nc] = true;
		}
	}
	return vis[N - x + 1][M - x + 1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> g[i][j], psa[i][j] = g[i][j] == 'X';
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
	int l = 0, r = min(N, M);
	while (l <= r) {
		int m = (l + r) >> 1;
		if (f(m)) l = m + 1;
		else r = m - 1;
	}
	cout << r << '\n';
	return 0;
}
