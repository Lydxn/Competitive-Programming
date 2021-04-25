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

char grid[100][100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> grid[i][j];

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == 'S') continue;
			int cnt = 0, tot = 0;
			for (int a = max(0, i - 1); a <= min(i + 1, r - 1); a++)
				for (int b = max(0, j - 1); b <= min(j + 1, c - 1); b++)
					if (!(a == i && b == j)) cnt += grid[a][b] == 'S', ++tot;
			ans += cnt * 2 < tot;
		}
	}
	cout << ans << '\n';
	return 0;
}
