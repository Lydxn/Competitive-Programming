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

int X[20001], Y[20001], dp[2][2001][2];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i], X[i] += 1000, Y[i] += 1000;
	X[0] = Y[0] = 1000;
	for (int i = N - 1; i >= 0; i--) {
		int cur = i & 1, prv = cur ^ 1;
		for (int j = 0; j <= 2000; j++) {
			dp[cur][j][0] = min(dp[prv][j][0] + abs(Y[i] - Y[i + 1]), dp[prv][Y[i]][1] + abs(j - X[i + 1]));
			dp[cur][j][1] = min(dp[prv][j][1] + abs(X[i] - X[i + 1]), dp[prv][X[i]][0] + abs(j - Y[i + 1]));
		}
	}
	cout << dp[0][1000][0] << '\n';
	return 0;
}
