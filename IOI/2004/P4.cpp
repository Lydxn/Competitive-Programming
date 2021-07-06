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

int dp[601][601];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int W, H, N, w, h;
	cin >> W >> H >> N;
	for (int i = 1; i <= W; i++)
		for (int j = 1; j <= H; j++)
			dp[i][j] = i * j;
	while (N--) cin >> w >> h, dp[w][h] = 0;
	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= H; j++) {
			for (int k = 1; k <= i / 2; k++)
				dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
			for (int k = 1; k <= j / 2; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
		}
	}
	cout << dp[W][H] << '\n';
	return 0;
}
