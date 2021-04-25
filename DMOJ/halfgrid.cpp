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

int x[2], y[2];
ll fact[2000001], inv_fact[1000001];

ll powmod(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD, y >>= 1;
	}
	return res;
}

ll ways(int n, int k) {
	return fact[n + k] * inv_fact[n] % MOD * inv_fact[k] % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int W, H, X;
	cin >> W >> H >> X;
	for (int i = 0; i < X; i++) cin >> x[i] >> y[i];

	fact[0] = 1;
	for (int i = 1; i <= W + H; i++) fact[i] = i * fact[i - 1] % MOD;

	int mx = max(W, H);
	inv_fact[mx] = powmod(fact[mx], MOD - 2);
	for (int i = mx - 1; i >= 0; i--) inv_fact[i] = (i + 1) * inv_fact[i + 1] % MOD;

	if (X == 0) cout << ways(W - 1, H - 1) << '\n';
	else if (X == 1) cout << (ways(W - 1, H - 1) - ways(x[0] - 1, y[0] - 1) * ways(W - x[0], H - y[0]) % MOD + MOD) % MOD << '\n';
	else {
		ll ans = ways(W - 1, H - 1);
		ans = (ans - ways(x[0] - 1, y[0] - 1) * ways(W - x[0], H - y[0]) % MOD + MOD) % MOD;
		ans = (ans - ways(x[1] - 1, y[1] - 1) * ways(W - x[1], H - y[1]) % MOD + MOD) % MOD;

		if (x[0] > x[1])
			swap(x[0], x[1]), swap(y[0], y[1]);
		if (y[0] <= y[1])
			ans = (ans + ways(x[0] - 1, y[0] - 1) * ways(x[1] - x[0], y[1] - y[0]) % MOD * ways(W - x[1], H - y[1]) % MOD + MOD) % MOD;
		cout << ans << '\n';
	}
	return 0;
}
