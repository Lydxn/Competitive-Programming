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

const int MX = 2000000;
ll f[MX + 1], invf[MX + 1];

int pm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD, b >>= 1;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	f[0] = 1;
	for (int i = 1; i <= MX; i++) f[i] = f[i - 1] * i % MOD;
	invf[MX] = pm(f[MX], MOD - 2);
	for (int i = MX - 1; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;

	int n, m;
	cin >> n >> m;
	cout << f[n + m - 1] * invf[m] % MOD * invf[n - 1] % MOD << '\n';
	return 0;
}
