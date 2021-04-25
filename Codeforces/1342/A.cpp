#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, x, y, a, b;
	cin >> t;
	while (t--) {
		cin >> x >> y >> a >> b;
		ll mn = abs(min(x, y)), mx = abs(max(x, y));
		if ((a > 0) + (b > 0) == 1) cout << (mn + mx) * a << '\n';
		else cout << min((mn + mx) * a, mn * b + (mx - mn) * a) << '\n';
	}
	return 0;
}
