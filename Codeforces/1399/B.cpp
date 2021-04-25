#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a[50], b[50];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		int ma = *min_element(a, a + n), mb = *min_element(b, b + n);
		ll ans = 0;
		for (int i = 0; i < n; i++) ans += max(a[i] - ma, b[i] - mb);

		cout << ans << '\n';
	}
	return 0;
}
