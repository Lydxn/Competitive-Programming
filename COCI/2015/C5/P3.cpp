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

int a[100000];
ll f[100001], invf[100001];

ll powmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD, b >>= 1;
	}
	return res;
}

ll C(int n, int k) {
	return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K; ll ans = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i];

	f[0] = 1;
	for (int i = 1; i <= N; i++) f[i] = f[i - 1] * i % MOD;
	invf[N] = powmod(f[N], MOD - 2);
	for (int i = N - 1; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;
	
	sort(a, a + N);
	for (int i = K - 1; i < N; i++) ans = (ans + a[i] * C(i, K - 1)) % MOD;
	cout << ans << '\n';
	return 0;
}
