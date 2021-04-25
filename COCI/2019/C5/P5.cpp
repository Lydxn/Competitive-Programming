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

int N, C[351][351], dp[351][351][2];

int solve(int idx, int t, bool yay) {
	if (idx == N + 1) return yay && t == 0;
	if (dp[idx][t][yay] != -1) return dp[idx][t][yay];
	int res = 0;
	for (int i = 0; i <= t; i++)
		res = (res + 1LL * C[t][i] * solve(idx + 1, t - i, yay | (idx == i))) % MOD;
	return dp[idx][t][yay] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	C[0][0] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= i; j++)
			C[i][j] = (C[i - 1][j] + (j ? C[i - 1][j - 1] : 0)) % MOD;
		
	memset(dp, -1, sizeof(dp));
	cout << solve(1, N, false) << '\n';
	return 0;
}
