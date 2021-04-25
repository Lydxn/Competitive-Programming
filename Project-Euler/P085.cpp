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

ll f(ll n, ll m) {
	return n * m * (n + 1) * (m + 1) / 4;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll cnt = INFL, ans = -1;
	for (int i = 1; i <= 2000000; i++) {
		int l = 1, r = 2000000;
		while (l < r) {
			int m = (l + r) >> 1;
			if (f(i, m) > 2000000) r = m;
			else l = m + 1;
		}

		ll t1 = f(i, r), t2 = f(i, r - 1);
		if (abs(t1 - 2000000) < cnt) cnt = abs(t1 - 2000000), ans = 1LL * i * r;
		if (abs(t2 - 2000000) < cnt) cnt = abs(t2 - 2000000), ans = 1LL * i * (r - 1);
	}
	cout << ans << '\n';
	return 0;
}
