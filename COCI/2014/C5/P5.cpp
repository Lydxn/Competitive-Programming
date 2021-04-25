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

int R, S, v[501][501];

int f(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void insert(int r, int s) {
	for (int i = 1; i <= S; i++) v[r][i] = min(v[r][i], (i - s) * (i - s));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int G, r, s; string what;
	cin >> R >> S;
	memset(v, INF, sizeof(v));
	for (int i = 1; i <= R; i++) {
		cin >> what;
		for (int j = 1; j <= S; j++)
			if (what[j - 1] == 'x') insert(i, j);
	}

	cin >> G;
	while (G--) {
		cin >> r >> s; int ans = INF;
		for (int i = 1; i <= R; i++) ans = min(ans, v[i][s] + (i - r) * (i - r));
		insert(r, s);
		cout << ans << '\n';
	}
	return 0;
}
