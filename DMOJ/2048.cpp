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

vector<vector<int>> grid(4, vector<int>(4)), tmp;
set<__uint128_t> vis;
int ans;

void dfs(vector<vector<int>> grid) {
	int cur = 0; __uint128_t hsh = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cur = max(cur, grid[i][j]), hsh = hsh << 5 | grid[i][j];

	if (vis.count(hsh)) return;
	vis.insert(hsh);
	ans = max(ans, cur);

	// swipe right
	tmp = grid;
	for (int i = 0; i < 4; i++) {
		for (int j = 3, p = -1; j >= 0; j--) {
			if (tmp[i][j]) {
				if (p != -1 && tmp[i][j] == tmp[i][p]) ++tmp[i][p], tmp[i][j] = 0, p = -1;
				else p = j;
			}
		}
		for (int j = 3, p = 3; j >= 0; j--) {
			if (tmp[i][p]) { --p; continue; }
			if (tmp[i][j]) tmp[i][p--] = tmp[i][j], tmp[i][j] = 0;
		}
	}
	dfs(tmp);

	// swipe left
	tmp = grid;
	for (int i = 0; i < 4; i++) {
		for (int j = 0, p = -1; j < 4; j++) {
			if (tmp[i][j]) {
				if (p != -1 && tmp[i][j] == tmp[i][p]) ++tmp[i][p], tmp[i][j] = 0, p = -1;
				else p = j;
			}
		}
		for (int j = 0, p = 0; j < 4; j++) {
			if (tmp[i][p]) { ++p; continue; }
			if (tmp[i][j]) tmp[i][p++] = tmp[i][j], tmp[i][j] = 0;
		}
	}
	dfs(tmp);

	// swipe down
	tmp = grid;
	for (int i = 0; i < 4; i++) {
		for (int j = 3, p = -1; j >= 0; j--) {
			if (tmp[j][i]) {
				if (p != -1 && tmp[j][i] == tmp[p][i]) ++tmp[p][i], tmp[j][i] = 0, p = -1;
				else p = j;
			}
		}
		for (int j = 3, p = 3; j >= 0; j--) {
			if (tmp[p][i]) { --p; continue; }
			if (tmp[j][i]) tmp[p--][i] = tmp[j][i], tmp[j][i] = 0;
		}
	}
	dfs(tmp);

	// swipe up
	tmp = grid;
	for (int i = 0; i < 4; i++) {
		for (int j = 0, p = -1; j < 4; j++) {
			if (tmp[j][i]) {
				if (p != -1 && tmp[j][i] == tmp[p][i]) ++tmp[p][i], tmp[j][i] = 0, p = -1;
				else p = j;
			}
		}
		for (int j = 0, p = 0; j < 4; j++) {
			if (tmp[p][i]) { ++p; continue; }
			if (tmp[j][i]) tmp[p++][i] = tmp[j][i], tmp[j][i] = 0;
		}
	}
	dfs(tmp);
}

void solve() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> grid[i][j], grid[i][j] = grid[i][j] ? __lg(grid[i][j]) : 0;

	ans = 0; dfs(grid);
	cout << (ans ? 1 << ans : 0) << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) solve();
	return 0;
}
