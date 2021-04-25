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

int dp[100000][2][4];
string K;

int solve(int pos, bool tight, int sub) {
	if (pos == int(K.size())) return sub == 2;
	if (dp[pos][tight][sub] != -1) return dp[pos][tight][sub];
	
	ll res = 0;
	for (int i = 0; i <= (tight ? K[pos] - '0' : 9); i++) {
		bool add = (sub == 0 && i == 1) || ((sub == 1 || sub == 2) && i == 0);
		res = (res + solve(pos + 1, K[pos] - '0' == i ? tight : false, sub + add)) % MOD;
	}
	return dp[pos][tight][sub] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, true, 0) << '\n';
	return 0;
}
