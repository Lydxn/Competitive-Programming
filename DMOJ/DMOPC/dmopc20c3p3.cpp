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

ll powmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		b >>= 1, a = a * a % MOD;
	}
	return res;
}

ll divmod(ll a, ll b) {
	return a * powmod(b, MOD - 2) % MOD;
}

ll A[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q, N, K, M, B;
	cin >> Q;
	while (Q--) {
		cin >> N >> M >> K >> B;
		ll ans = 0;
		if (K == 1 && N % 3 == 0) {
			ans = divmod(powmod(B, 2) * (powmod(B, N) - 1) % MOD, (powmod(B, 3) - 1 + MOD) % MOD) * M % MOD;
		} else if (K == 2 && N % 2 == 0 && M % 2 == 0) {
			ans = divmod(B * (powmod(B, N) - 1) % MOD, powmod(B, 2) - 1) * (M / 2) % MOD;
		} else {
			if (M % (K + 2)) { cout << "-1\n"; continue; }
			ans = divmod(powmod(B, N) - 1, B - 1) * (M / (K + 2)) % MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}
