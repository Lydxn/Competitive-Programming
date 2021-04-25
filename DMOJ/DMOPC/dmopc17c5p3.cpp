#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll A, gcd, ans = 0;
	cin >> N >> A; gcd = A, --N;
	while (N--) cin >> A, gcd = __gcd(gcd, A);

	while ((gcd & 1) == 0) gcd >>= 1, ans = 2;
	for (ll i = 3; i * i <= gcd; i += 2) {
		while (gcd % i == 0) gcd /= i, ans = max(ans, i);
	}
	ans = max(ans, gcd);

	if (ans == 1) cout << "DNE\n";
	else cout << ans << '\n';
	return 0;
}
