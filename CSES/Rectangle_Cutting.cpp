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

int dp[501][501];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	memset(dp, INF, sizeof(dp));
	for (int i = 1; i <= min(a, b); i++) dp[i][i] = 0;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k < i; k++)
				dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
			for (int k = 1; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
		}
	}
	cout << dp[a][b] << '\n';
	return 0;
}
