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

int N, grid[10][10];
bool vis[10];

bool covers(int x, int y) {
	int l = INF, r = -INF, d = -INF, u = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] != y) continue;
			l = min(l, j), r = max(r, j), u = min(u, i), d = max(d, i);
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (grid[i][j] == x && l <= j && j <= r && u <= i && i <= d)
				return true;
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);

	char c;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> c, vis[grid[i][j] = c - '0'] = true;

	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		if (!vis[i]) continue;
		bool bad = false;
		for (int j = 1; j <= 9; j++)
			if (j != i && covers(i, j)) bad = true;
		ans += !bad;
	}
	cout << ans << '\n';
	return 0;
}
