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

char grid[1000][1000];
bool vis[1000][1000];
unordered_set<int> ss;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			int r = i, c = j;
			while (!vis[r][c]) {
				vis[r][c] = true, ss.insert(r << 10 | c);
				switch (grid[r][c]) {
					case 'N': --r; break;
					case 'E': ++c; break;
					case 'S': ++r; break;
					case 'W': --c; break;
				}
			}
			ans += ss.count(r << 10 | c), ss.clear();
		}
	}
	cout << ans << '\n';
	return 0;
}
