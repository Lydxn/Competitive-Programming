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

int b[501], dp[501][5001], ans[501];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T >> N; dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> b[i];
		for (int j = 0; j <= T; j++) {
			if (dp[i - 1][j]) dp[i][j] = 1;
			if (j >= b[i] && dp[i - 1][j - b[i]]) dp[i][j] = 2;
		}
	}

	int s = T;
	while (!dp[N][s]) --s;
	for (int i = N; i; i--) {
		ans[i] = dp[i][s];
		if (ans[i] == 2) s -= b[i];
	}
	
	for (int i = 1, l = 0, r = 0; i <= N; i++) {
		if (ans[i] == 1) cout << l << ' ', l += b[i];
		else cout << r << ' ', r += b[i];
	}
	cout << '\n';
	return 0;
}
