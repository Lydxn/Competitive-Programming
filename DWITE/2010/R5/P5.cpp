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

int N, M, grid[20][20];
bool vis[20][20];

int dfs(int x, int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M || vis[i][j]) return 0;
	vis[i][j] = true;
	return 1 + dfs(x, i + 1, j) + dfs(x, i - 1, j) + dfs(x, i, j - 1) + dfs(x, i, j + 1);
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];
	int ans = 0;
	for (int x = 0; x <= 50; x++) {
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (grid[i][j] > x)
					vis[i][j] = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
					dfs(x, i, j);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				ans += !vis[i][j];
	}
	cout << ans << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) solve();
	return 0;
}
