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

int grid[50][50], dp[50][50][50][50];

int solve(int r1, int c1, int r2, int c2) {
	if (r1 == r2 && c1 == c2) return 0;
	if (dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];

	int ans = INF;
	for (int i = r1; i < r2; i++) ans = min(ans, solve(r1, c1, i, c2) + solve(i + 1, c1, r2, c2));
	for (int i = c1; i < c2; i++) ans = min(ans, solve(r1, c1, r2, i) + solve(r1, i + 1, r2, c2));
	return dp[r1][c1][r2][c2] = ans + grid[r2 + 1][c2 + 1] - grid[r1][c2 + 1] - grid[r2 + 1][c1] + grid[r1][c1];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> grid[i][j], grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, N - 1, M - 1) << '\n';
	return 0;
}
