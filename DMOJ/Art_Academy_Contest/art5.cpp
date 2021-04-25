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

#define dist(i, j) (abs(x[i] - x[j]) + abs(y[i] - y[j]))

int dp[2003][2003], x[2003], y[2003];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N + 2; i++) cin >> x[i] >> y[i];

	memset(dp, INF, sizeof(dp));
	dp[2][1] = 0;
	for (int i = 3; i <= N + 2; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist(i - 1, i));
			dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + dist(j, i));
		}
	}

	int ans = INF;
	for (int i = 1; i <= N + 2; i++) ans = min(ans, dp[N + 2][i]);
	cout << ans << '\n';
	return 0;
}
