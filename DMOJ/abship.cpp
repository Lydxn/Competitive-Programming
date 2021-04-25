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

char grid[500][500];
int M, N, S, cnt[250000], ships[500][500], sidx;
bool vis[500][500];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(int i, int j, int sidx) {
	queue<pii> q; q.emplace(i, j), ships[i][j] = sidx;
	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();
		for (auto d : dir) {
			int nr = cr + d.first, nc = cc + d.second;
			if (nr >= 0 && nr < M && nc >= 0 && nc < N && !vis[nr][nc] && grid[nr][nc] == 'X')
				q.emplace(nr, nc), vis[nr][nc] = true, ships[nr][nc] = sidx;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> S;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (!vis[i][j] && grid[i][j] == 'X') bfs(i, j, ++sidx);

	int ans = 0;
	for (int i = 0; i <= M - S; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0, cur = 0; j < N; j++) {
			for (int k = i; k < i + S; k++)
				if (ships[k][j] && ++cnt[ships[k][j]] == 1) ++cur;

			if (j >= S)
				for (int k = i; k < i + S; k++)
					if (ships[k][j - S] && --cnt[ships[k][j - S]] == 0) --cur;

			if (j >= S - 1) ans += cur;
		}
	}

	cout << fixed << setprecision(12) << (double) ans / ((M - S + 1) * (N - S + 1)) << '\n';
	return 0;
}
