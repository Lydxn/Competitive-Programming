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

const int MX = 101;
bool g[102][102], vis[102][102];
int ans;

bool in(int x, int y) {
	return x >= 0 && x <= MX && y >= 0 && y <= MX && g[x][y];
}

void dfs(int x, int y) {
	if (x < 0 || x > MX || y < 0 || y > MX || vis[x][y] || g[x][y]) return;
	vis[x][y] = true;
	ans += in(x + 1, y) + in(x, y + 1) + in(x - 1, y) + in(x, y - 1);
	dfs(x + 1, y), dfs(x, y + 1), dfs(x - 1, y), dfs(x, y - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);

	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x >> y, g[x][y] = true;
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}
