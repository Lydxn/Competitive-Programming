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
const int MOD = 998244353;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

ll F[100001], IF[100001];

ll powmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD, b >>= 1;
	}
	return res;
}

ll f(ll n, ll k) {
	return k * powmod(k - 1, n - 1) % MOD;
}

ll nCr(ll n, ll k) {
	return F[n] * IF[k] % MOD * IF[n - k] % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N, K, ans = 0;
	cin >> N >> K;
	F[0] = 1;
	for (int i = 1; i <= K; i++) F[i] = F[i - 1] * i % MOD;
	IF[K] = powmod(F[K], MOD - 2);
	for (int i = K - 1; i >= 0; i--) IF[i] = IF[i + 1] * (i + 1) % MOD;
	for (int i = 0; i <= K; i++) {
		if ((K - i) % 2 == 0) ans = (ans + f(N, i) * nCr(K, i)) % MOD;
		else ans = (ans - f(N, i) * nCr(K, i) % MOD + MOD) % MOD;
	}
	cout << ans << '\n';
	return 0;
}
