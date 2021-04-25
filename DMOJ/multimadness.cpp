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

int x[1000000], y[1000000];
ll f[1000001], invf[1000001];

ll powmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD, b >>= 1;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i], mx = max(mx, y[i]);
	f[0] = 1;
	for (int i = 1; i <= mx; i++) f[i] = f[i - 1] * i % MOD;
	invf[mx] = powmod(f[mx], MOD - 2);
	for (int i = mx - 1; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;
	for (int i = 0; i < N; i++) cout << f[y[i]] * invf[x[i] - 1] % MOD << '\n';
	return 0;
}
