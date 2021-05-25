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

int M[100000], P[100000][7], dp[100000][7][3], ch[100000][7][3];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M[i];
		for (int j = 0; j < M[i]; j++) cin >> P[i][j];
	}
	memset(dp, INF, sizeof(dp));
	for (int i = 0; i < M[0]; i++) dp[0][i][0] = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M[i]; j++) {
			for (int k = 0; k < M[i - 1]; k++) {
				for (int l = 0; l < 3; l++) {
					int diff = P[i][j] - P[i - 1][k];
					int dir = diff == 0 ? 0 : diff > 0 ? 1 : 2;
					if (dp[i - 1][k][l] + abs(diff) < dp[i][j][dir]) {
						dp[i][j][dir] = dp[i - 1][k][l] + abs(diff);
						ch[i][j][dir] = ch[i - 1][k][l] + (dir != l && i != 1);
					} else if (dp[i - 1][k][l] + abs(diff) == dp[i][j][dir])
						ch[i][j][dir] = min(ch[i][j][dir], ch[i - 1][k][l] + (dir != l && i != 1));
				}
			}
		}
	}
	int ans1 = INF, ans2 = 0;
	for (int i = 0; i < M[N - 1]; i++)
		for (int j = 0; j < 3; j++)
			if (dp[N - 1][i][j] < ans1)
				ans1 = dp[N - 1][i][j], ans2 = ch[N - 1][i][j];
			else if (dp[N - 1][i][j] == ans1)
				ans2 = min(ans2, ch[N - 1][i][j]);
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}
