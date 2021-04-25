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

ll dp[19][2][11][2];

ll rec(string &s, int idx, int tight, int pd, int nonz) {
	if (idx == int(s.size())) return 1;
	if (dp[idx][tight][pd][nonz] != -1) return dp[idx][tight][pd][nonz];
	ll res = 0;
	for (int i = 0; i <= (tight ? s[idx] - '0' : 9); i++)
		if (pd != i)
			res += rec(s, idx + 1, tight && (i == s[idx] - '0'), nonz || i ? i : 10, nonz || i);
	return dp[idx][tight][pd][nonz] = res;
}

ll solve(string s) {
	memset(dp, -1, sizeof(dp));
	return rec(s, 0, true, 10, false);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	cout << solve(to_string(b)) - solve(to_string(a - 1)) << '\n';
 	return 0;
}
