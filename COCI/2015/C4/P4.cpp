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

ll depth(ll x, int K) {
	if (K == 1) return x;
	ll d = 0, a = 0, b = 1;
	while (x > a) a += b, b *= K, ++d;
	return d;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, Q; ll N, x, y;
	cin >> N >> K >> Q;
	while (Q--) {
		cin >> x >> y;
		ll dx = depth(x, K), dy = depth(y, K);
		if (dx < dy) swap(dx, dy), swap(x, y);

		ll ans = dx - dy;
		for (int i = 0; i < ans; i++) x = (x - 2 + K) / K;
		while (x != y) x = (x - 2 + K) / K, y = (y - 2 + K) / K, ans += 2;
		cout << ans << '\n';
	}
	return 0;
}
