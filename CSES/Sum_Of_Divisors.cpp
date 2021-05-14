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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n; __uint128_t ans = 0;
	cin >> n;
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		__uint128_t s = (__uint128_t) (r - l + 1) * (l + r) / 2;
		ans += n / l * s;
	}
	cout << (ll) (ans % MOD) << '\n';
	return 0;
}
