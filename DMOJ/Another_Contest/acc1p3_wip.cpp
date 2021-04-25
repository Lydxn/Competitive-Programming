// this is too hard :(

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;
ll a[100000], b[100000];
int N; ll T;

bool f(ll x) {
	ll tot = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] >= x) {
			ll iter = (a[i] - x + b[i] - 1) / b[i];
			tot += iter;
			if (tot > T) return false;
		}
	}
	return true;
}

ll solve(ll x) {
	ll res = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] >= x) {
			ll iter = (a[i] - x + b[i] - 1) / b[i];
			res = (res + (a[i] % MOD * iter % MOD) % MOD - (((b[i] % MOD) * (iter % MOD)) % MOD * (iter - 1) % MOD) % MOD / 2) % MOD;
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i];

	ll l = 0, r = 1e18, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (f(mid)) r = mid;
		else l = mid + 1;
	}

	cout << solve(r) << '\n';
	return 0;
}
