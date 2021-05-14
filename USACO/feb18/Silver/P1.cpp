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

int x[100000], c[100000], g[100000], gidx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);

	int L, N, rf, rb;
	cin >> L >> N >> rf >> rb;
	for (int i = 0; i < N; i++) cin >> x[i] >> c[i];
	for (int i = N - 1, cur = 0; i >= 0; i--)
		if (c[i] > cur) cur = c[i], g[gidx++] = i;
	ll ans = 0, cf = 0, cb = 0;
	for (int i = gidx - 1; i >= 0; i--) {
		ll d = i == gidx - 1 ? x[g[i]] : x[g[i]] - x[g[i + 1]];
		cf += d * rf, cb += d * rb;
		ans += (cf - cb) * c[g[i]], cb = cf;
	}
	cout << ans << '\n';
	return 0;
}
