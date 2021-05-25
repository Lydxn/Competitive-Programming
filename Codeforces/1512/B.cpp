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

char g[400][400];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int r1 = -1, c1 = -1, r2 = -1, c2 = -2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> g[i][j];
				if (g[i][j] == '*') {
					if (r1 == -1) r1 = i, c1 = j;
					else r2 = i, c2 = j;
				}
			}
		}
		if (r1 == r2) g[(r1 + 1) % n][c1] = g[(r2 + 1) % n][c2] = '*';
		else if (c1 == c2) g[r1][(c1 + 1) % n] = g[r2][(c2 + 1) % n] = '*';
		else g[r1][c2] = g[r2][c1] = '*';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << g[i][j];
			cout << '\n';
		}
	}
	return 0;
}
