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

int n, m;
char g[1000][1000];
bool vis[1000][1000];

void dfs(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] == '#' || vis[i][j]) return;
	vis[i][j] = true;
	dfs(i + 1, j), dfs(i, j + 1), dfs(i - 1, j), dfs(i, j - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> g[i][j];
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == '.' && !vis[i][j]) ++ans, dfs(i, j);
	cout << ans << '\n';
	return 0;
}
