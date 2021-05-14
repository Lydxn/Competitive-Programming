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

ll a[20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n, ans = 0; int k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) cin >> a[i];
	for (int i = 1; i < 1 << k; i++) {
		__uint128_t p = 1; bool bad = false;
		for (int j = 0; j < k && !bad; j++)
			if (i & (1 << j)) p *= a[j], bad |= p > n;
		if (!bad) ans += n / p * (__builtin_popcount(i) % 2 ? 1 : -1);
	}
	cout << ans << '\n';
	return 0;
}
