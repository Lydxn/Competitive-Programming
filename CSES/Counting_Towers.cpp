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

ll dp1[1000001], dp2[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	dp1[1] = dp2[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		dp1[i] = (dp1[i] + dp2[i - 1] + 2 * dp1[i - 1]) % MOD;
		dp2[i] = (dp2[i] + dp1[i - 1] + 4 * dp2[i - 1]) % MOD;
	}
	
	int t, n;
	cin >> t;
	while (t--) cin >> n, cout << (dp1[n] + dp2[n]) % MOD << '\n';
	return 0;
}
