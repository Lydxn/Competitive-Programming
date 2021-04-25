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

char grid[50][50];
pii dir[8] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
int m, n;

bool found(string s, int r, int c, int dr, int dc) {
	string t = "";
	int sz = s.size();
	while (r >= 0 && r < m && c >= 0 && c < n && sz--) t += grid[r][c], r += dr, c += dc;
	return s == t;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, k; string s;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i][j], grid[i][j] = tolower(grid[i][j]);

		cin >> k;
		while (k--) {
			cin >> s;
			for (int i = 0; i < int(s.size()); i++) s[i] = tolower(s[i]);
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					for (auto d : dir) {
						int dr = d.first, dc = d.second;
						if (found(s, i, j, dr, dc)) {
							cout << i + 1 << ' ' << j + 1 << '\n';
							goto done;
						}
					}
				}
			}
			done:;
		}
		cout << '\n';
	}
	return 0;
}
