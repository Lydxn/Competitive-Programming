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

bool grid[17][17], tmp[17][17];
int cur;

void click(int r, int c) {
	++cur;
	grid[r][c] ^= true;
	grid[r + 1][c] ^= true, grid[r - 1][c] ^= true;
	grid[r][c + 1] ^= true, grid[r][c - 1] ^= true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C; char ch;
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> ch, tmp[i][j] = ch == 'X';

	int ans = INF;
	for (int i = 0; i < (1 << C); i++) {
		memcpy(grid, tmp, sizeof(tmp)), cur = 0;
		for (int j = 0; j < C; j++)
			if (i & (1 << j)) click(1, j + 1);

		for (int i = 1; i < R; i++)
			for (int j = 1; j <= C; j++)
				if (grid[i][j]) click(i + 1, j);

		for (int j = 1; j <= C; j++)
			if (grid[R][j]) goto nxt;
		ans = min(ans, cur); nxt:;
	}

	if (ans == INF) cout << "Damaged billboard.\n";
	else cout << "You have to tap " << ans << " tiles.\n";
	return 0;
}
