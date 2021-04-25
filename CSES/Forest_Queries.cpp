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

int b[1001][1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, y1, x1, y2, x2; char c;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> c, b[i][j] = (c == '*') + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
	while (q--) {
		cin >> y1 >> x1 >> y2 >> x2;
		cout << b[y2][x2] - b[y1 - 1][x2] - b[y2][x1 - 1] + b[y1 - 1][x1 - 1] << '\n';
	}
	return 0;
}
