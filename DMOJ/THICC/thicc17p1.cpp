#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

ll modpow(ll a, ll b) {
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

	int n, m, c[100];
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> c[i];

	sort(c, c + n);
	ll ans = 0;
	for (int i = n - 1, k = 0; i >= 0; i -= m, k += 1)
		for (int j = i; j >= max(0, i - m + 1); j--)
			ans = (ans + modpow(c[j], k)) % MOD;
	cout << ans << '\n';
	return 0;
}
