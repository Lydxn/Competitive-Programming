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

char g[51][51];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> g[i][j];
		for (int b = 0; b < 2; b++) {
			bool ok = true;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (g[i][j] != '.')
						ok &= g[i][j] == "RW"[(i + j + b) & 1];
			if (ok) {
				cout << "YES\n";
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++)
						cout << "RW"[(i + j + b) & 1];
					cout << '\n';
				}
				goto nxt;
			}
		}
		cout << "NO\n"; nxt:;
	}
	return 0;
}
