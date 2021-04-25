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
const int MOD = 10007;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int dp[100000], p[256];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	dp[0] = 1;
	memset(p, -1, sizeof(p));
	for (int i = 1; i <= int(s.size()); i++) {
		dp[i] = (dp[i - 1] << 1) % MOD;
		if (p[s[i - 1]] != -1) dp[i] = (dp[i] - dp[p[s[i - 1]] - 1] + MOD) % MOD;
		p[s[i - 1]] = i;
	}
	cout << dp[s.size()] - 1 << '\n';
	return 0;
}
