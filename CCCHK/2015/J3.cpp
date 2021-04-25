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

bool grid[101][101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, x, y, cnt = 0;
	cin >> N >> M;
	memset(grid, true, sizeof(grid));
	while (M--) {
		cin >> x >> y;
		for (int i = 1; i <= N; i++) {
			grid[x][i] = grid[i][y] = false;
			if (1 <= i - x + y && i - x + y <= N) grid[i][i - x + y] = false;
			if (1 <= x + y - i && x + y - i <= N) grid[i][x + y - i] = false;
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cnt += grid[i][j];
	cout << cnt << '\n';
	return 0;
}
