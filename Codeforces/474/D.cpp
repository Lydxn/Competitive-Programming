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

int dp[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, k, a, b;
	cin >> t >> k;
	for (int i = 0; i < k; i++) dp[i] = 1;
	for (int i = k; i <= 100000; i++) dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
	for (int i = 1; i <= 100000; i++) dp[i] = (dp[i] + dp[i - 1]) % MOD;
	while (t--) cin >> a >> b, cout << (dp[b] - dp[a - 1] + MOD) % MOD << '\n';
	return 0;
}
