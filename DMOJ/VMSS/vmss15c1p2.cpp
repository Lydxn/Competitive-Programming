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
bool vis[100][100];
int r, c;

void solve(int i, int j) {
	if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 'X' || vis[i][j]) return;
	vis[i][j] = true;
	solve(i + 1, j), solve(i, j + 1), solve(i - 1, j), solve(i, j - 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> grid[i][j];

	int cnt = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (!vis[i][j] && grid[i][j] == '.')
				solve(i, j), ++cnt;
	cout << cnt << '\n';
	return 0;
}
