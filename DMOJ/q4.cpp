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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; char grid[4][4];
	cin >> T;
	while (T--) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> grid[i][j];

		bool yay = false;
		for (int i = 0; i < 4; i++)
			yay |= (grid[i][0] == 'X' && grid[i][1] == 'X' && grid[i][2] == 'X' && grid[i][3] == 'X')
				|| (grid[0][i] == 'X' && grid[1][i] == 'X' && grid[2][i] == 'X' && grid[3][i] == 'X');
		yay |= grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X' && grid[3][3] == 'X';
		yay |= grid[0][3] == 'X' && grid[1][2] == 'X' && grid[2][1] == 'X' && grid[3][0] == 'X';
		cout << (yay ? "Yes" : "No") << '\n';
	}
	return 0;
}
