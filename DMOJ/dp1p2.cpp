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

int coins[1000], psa[1001], dp[1000][1000];

int solve(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return coins[l];
	return dp[l][r] = psa[r + 1] - psa[l] - min(solve(l + 1, r), solve(l, r - 1));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> coins[i];
	for (int i = 1; i <= N; i++) psa[i] = psa[i - 1] + coins[i - 1];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, N - 1) << '\n';
	return 0;
}
