#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int dp[2][1 << 20];
vector<int> masks;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;
	for (int i = 0; i < (1 << (C - 2)); i++)
		if (!(i & (i >> 1)) && !(i & (i >> 2)))
			masks.push_back(i);

	for (int m : masks) dp[0][m] = 1;
	for (int i = 1; i < R - 1; i++) {
		memset(dp[i & 1], 0, sizeof(dp[i & 1]));
		for (int j : masks)
			for (int k : masks)
				if (!(j & (k << 1 | k | k >> 1)))
					dp[i & 1][k] = (dp[i & 1][k] + dp[(i & 1) ^ 1][j]) % MOD;
	}

	int ans = 0;
	for (int i = 0; i < (1 << (C - 2)); i++)
		ans = (ans + dp[R & 1][i]) % MOD;
	cout << (ans - 1 + MOD) % MOD << '\n';
	return 0;
}
