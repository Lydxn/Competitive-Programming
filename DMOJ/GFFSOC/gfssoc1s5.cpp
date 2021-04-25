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

int dp[51][51][51][51], T[51][51], V[51][51];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C, S, B, K, M, t, v, r, c;
	cin >> R >> C >> S >> B >> K >> M;
	while (S--) {
		cin >> t >> v >> c >> r;
		T[r][c] = t, V[r][c] = v;
	}

	memset(dp, -INF, sizeof(dp));
	dp[0][1][0][0] = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			t = T[i][j], v = V[i][j];
			int ml = max(1, j - M), mr = min(j + M, C);
			for (int k = 0; k <= K; k++) {
				for (int l = 0; l < B; l++) {
					for (int m = ml; m <= mr; m++) {
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][m][k][l]);
						if (k && l >= t)
							dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][m][k - 1][l - t] + v);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= C; i++)
		for (int j = 0; j <= K; j++)
			for (int k = 0; k < B; k++)
				ans = max(ans, dp[R][i][j][k]);
	cout << ans << '\n';
	return 0;
}
