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

const int MX = 1e6;
ll f[MX + 1], invf[MX + 1];

ll pm(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD, b >>= 1;
	}
	return res;
}

ll C(ll n, ll k) {
	if (n < k) return 0;
	return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	f[0] = 1;
	for (int i = 1; i <= MX; i++) f[i] = f[i - 1] * i % MOD;
	invf[MX] = pm(f[MX], MOD - 2);
	for (int i = MX - 1; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;

	int T, N, K, Q;
	cin >> T;
	while (T--) {
		cin >> N >> K >> Q;
		cout << C(N - 1LL * K * Q + 1, Q) << '\n';
	}
	return 0;
}
