#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

const int MAGIC = 1000000039;
ll x[3000], y[3000];
gp_hash_table<ll, int> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		mp.clear();
		for (int j = i + 1; j < N; j++) {
			ll dx = x[i] - x[j], dy = y[i] - y[j], g = __gcd(dx, dy);
			++mp[(dx / g) * MAGIC + (dy / g)];
		}

		ll pts = N - i - 1;
		ans += pts * (pts - 1) / 2;
		for (auto j : mp) ans -= j.second * (j.second - 1) / 2;
	}
	cout << ans << '\n';
	return 0;
}
