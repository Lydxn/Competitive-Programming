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

char G[10];
int dp[1 << 10], nxt[1 << 10];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	memset(dp, INF, sizeof(dp)); dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> G;
		for (int j = 0; j < m; j++) {
			memset(nxt, INF, sizeof(nxt));
			for (int k = 0; k < 1 << m; k++) {
				if (k & (1 << j)) {
					if (G[j] == '#')
						nxt[k] = min(dp[k], dp[k ^ (1 << j)] + 1);
				} else
					nxt[k] = min(dp[k], dp[k ^ (1 << j)])
				+ (G[j] == '#' && (j == 0 || G[j - 1] == '.' || (k & (1 << (j - 1)))));
			}
			memcpy(dp, nxt, sizeof(dp));
		}
	}

	int mn = INF;
	for (int i = 0; i < 1 << m; i++) mn = min(mn, dp[i]);
	cout << mn << '\n';
	return 0;
}
