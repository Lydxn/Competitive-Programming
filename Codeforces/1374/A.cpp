#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, x, y, n;
	cin >> t;
	while (t--) {
		cin >> x >> y >> n;
		int ans = n - n % x + y;
		if (ans > n) ans -= x;
		cout << ans << '\n';
	}
	return 0;
}
