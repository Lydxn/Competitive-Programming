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

int dp[100000][101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n >> m >> x;
	if (x)
		dp[0][x] = 1;
	else
		for (int i = 1; i <= m; i++) dp[0][i] = 1;
		
	for (int i = 1; i < n; i++) {
		cin >> x;
		if (x) {
			for (int j : {x - 1, x, x + 1})
				if (1 <= j && j <= m)
					dp[i][x] = (dp[i][x] + dp[i - 1][j]) % MOD;
		} else {
			for (int j = 1; j <= m; j++)
				for (int k : {j - 1, j, j + 1})
					if (1 <= k && k <= m)
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) ans = (ans + dp[n - 1][i]) % MOD;
	cout << ans << '\n';
	return 0;
}
