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

int A[2000];
ll C[2000];

ll powmod(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % MOD;
		x = x * x % MOD, y >>= 1;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> M;

	C[0] = 1;
	for (int i = 1; i < N; i++) C[i] = C[i - 1] * (M + i - 1) % MOD * powmod(i, MOD - 2) % MOD;

	for (int i = 0; i < N; i++) {
		ll sum = 0;
		for (int j = 0; j <= i; j++)
			sum = (sum + C[j] * A[i - j] % MOD) % MOD;
		cout << sum << ' ';
	}
	cout << '\n';
	return 0;
}
