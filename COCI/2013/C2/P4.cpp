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

int N, d[1500][1500], dp[1500][1500];

int solve(int l, int r) {
	if (r == N - 1) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	return dp[l][r] = min(d[l][r + 1] + solve(r, r + 1), d[r][r + 1] + solve(l, r + 1));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> d[i][j];
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << '\n';
	return 0;
}
