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

bool g[1001][1000];
int n, bit[1001][1001];

void update(int i, int j, int v) {
	for (int ti = i; ti <= n; ti += ti & -ti)
		for (int tj = j; tj <= n; tj += tj & -tj)
			bit[ti][tj] += v;
}

int query(int i, int j) {
	int res = 0;
	for (int ti = i; ti; ti -= ti & -ti)
		for (int tj = j; tj; tj -= tj & -tj)
			res += bit[ti][tj];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int q, op, x, y, x1, y1, x2, y2; char ch;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ch;
			if (ch == '*') g[i][j] = true, update(i, j, 1);
		}
	}

	while (q--) {
		cin >> op;
		if (op == 1) cin >> y >> x, update(y, x, g[y][x] ? -1 : 1), g[y][x] ^= true;
		else cin >> y1 >> x1 >> y2 >> x2, cout << query(y2, x2) - query(y1 - 1, x2) - query(y2, x1 - 1) + query(y1 - 1, x1 - 1) << '\n';
	}
	return 0;
}
