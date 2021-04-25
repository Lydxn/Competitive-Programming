#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; ll a, K;
	cin >> t;
	while (t--) {
		cin >> a >> K;
		for (ll i = 0; i < K - 1; i++) {
			ll tmp = a, mn = 9, mx = 0;
			while (tmp) mn = min(mn, tmp % 10), mx = max(mx, tmp % 10), tmp /= 10;

			if (mn == 0 || mx == 0) break;
			a += mn * mx;
		}
		cout << a << '\n';
	}
	return 0;
}
