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

char grid[50][50];
int dp[50][50][50];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int S, R, C;
	cin >> S;
	while (S--) {
		cin >> R >> C;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				cin >> grid[i][j];

		memset(dp, -INF, sizeof(dp));
		for (int i = 0; i < C; i++)
			for (int j = 0; j < C; j++)
				if (i != j && grid[0][i] != '#' && grid[0][j] != '#')
					dp[0][i][j] = abs(i - j) == 1;

		for (int i = 1; i < R; i++) {
			for (int j = 0; j < C; j++) {
				for (int k = j + 1; k < C; k++) {
					if (j == k || grid[i][j] == '#' || grid[i][k] == '#') continue;
					for (int a = -1; a <= 1; a++) {
						for (int b = -1; b <= 1; b++) {
							int nj = j + a, nk = k + b;
							if (nj < 0 || nj >= C || nk < 0 || nk >= C || dp[i - 1][nj][nk] < 0)
								continue;
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][nj][nk] + (abs(j - k) == 1));
						}
					}
				}
			}
		}

		int ans = -INF;
		for (int i = 0; i < C; i++)
			for (int j = i + 1; j < C; j++)
				ans = max(ans, dp[R - 1][i][j]);

		if (ans < 0) cout << "Detour\n";
		else cout << ans << '\n';
	}
	return 0;
}
