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

ll C[101][101], dp[101][101], pdp[101][101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, A, B, K;
	cin >> N >> M >> A >> B >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> C[i][j];
	memset(pdp, -INFL, sizeof(pdp)); pdp[A][B] = 0;
	ll ans = -INFL;
	for (int i = 1; i <= min(N * M, K / 2); i++) {
		memset(dp, -INFL, sizeof(dp));
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= M; k++)
				for (int d = 0; d < 4; d++) {
					int x = j + dx[d], y = k + dy[d];
					if (x > 0 && x <= N && y > 0 && y <= M) {
						dp[j][k] = max(dp[j][k], pdp[x][y] + C[j][k]);
						ans = max(ans, 2 * dp[j][k] - C[j][k] + (K / 2 - i) * (C[j][k] + C[x][y]));
					}
				}
		memcpy(pdp, dp, sizeof(pdp));
	}
	cout << ans << '\n';
	return 0;
}
