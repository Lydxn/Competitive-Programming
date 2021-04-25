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

char grid[101][100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, H, W, N; char op;
	cin >> T;
	while (T--) {
		cin >> H >> W >> N;
		for (int i = 0; i < W; i++) grid[0][i] = 'E';
		for (int i = 1; i <= H; i++)
			for (int j = 0; j < W; j++)
				cin >> grid[i][j];

		int r = 0, c = 0, ans = 0;
		while (N--) {
			cin >> op;
			while (r < H && grid[r + 1][c] == 'E') ++r;
			if (op == 'L' && c > 0 && grid[r][c - 1] != 'S') --c;
			else if (op == 'R' && c < W - 1 && grid[r][c + 1] != 'S') ++c;
			else if (op == 'D' && r < H && grid[r + 1][c] != 'S') ++r;

			if (grid[r][c] == 'T') ++ans;
			grid[r][c] = 'E';
		}
		cout << ans << '\n';
	}
	return 0;
}
