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

pii p[100001];
ll dp[100001], fact[2000001], inv_fact[1000001];

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

	int H, W, N;
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) cin >> p[i].first >> p[i].second;

	fact[0] = 1;
	for (int i = 1; i <= W + H; i++) fact[i] = i * fact[i - 1] % MOD;

	int mx = max(W, H);
	inv_fact[mx] = powmod(fact[mx], MOD - 2);
	for (int i = mx - 1; i >= 0; i--) inv_fact[i] = (i + 1) * inv_fact[i + 1] % MOD;

	sort(p, p + N); p[N] = {H, W};
	for (int i = 0; i <= N; i++) {
		ll res = ways(p[i].first - 1, p[i].second - 1);
		for (int j = 0; j < i; j++)
			if (p[j].second <= p[i].second)
				res = (res - dp[j] * ways(p[i].first - p[j].first, p[i].second - p[j].second) % MOD + MOD) % MOD;
		dp[i] = res;
	}
	cout << dp[N] << '\n';
	return 0;
}
