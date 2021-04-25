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

int n[1000], dp[1000][1000];

int solve(int l, int r) {
	if (l > r) return 0;
	if (l == r) return 1;
	if (dp[l][r] != -1) return dp[l][r];
	int res = 1 + min(solve(l + 1, r), solve(l, r - 1));
	for (int i = l + 1; i <= r; i++)
		if (n[l] == n[i])
			res = min(res, solve(l + 1, i - 1) + min(solve(i, r), solve(i + 1, r) + 1));
	return dp[l][r] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> n[i];
	
	memset(dp, -1, sizeof(dp));
	cout << solve(0, N - 1) << '\n';
	return 0;
}
