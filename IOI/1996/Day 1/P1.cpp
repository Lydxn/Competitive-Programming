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

int a[100], dp[100][100];

int solve(int l, int r) {
	if (l > r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	return dp[l][r] = max(min(solve(l + 2, r), solve(l + 1, r - 1)) + a[l], min(solve(l, r - 2), solve(l + 1, r - 1)) + a[r]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i], sum += a[i];

	memset(dp, -1, sizeof(dp));
	solve(0, N - 1);
	cout << dp[0][N - 1] << ' ' << sum - dp[0][N - 1] << '\n';
	return 0;
}
