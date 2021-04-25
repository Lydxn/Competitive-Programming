#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, a[3], n;
	cin >> t;
	while (t--) {
		cin >> a[0] >> a[1] >> a[2] >> n;
		sort(a, a + 3); int amount = 2 * a[2] - a[1] - a[0];
		cout << (amount <= n && (n - amount) % 3 == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}
