#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, k, a[60], b[30];
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		sort(b, b + n, greater<int>());
		for (int i = 0; i < k; i++) a[i + n] = b[i];

		sort(a, a + n + k, greater<int>());
		int sum = 0;
		for (int i = 0; i < n; i++) sum += a[i];
		cout << sum << '\n';
	}
	return 0;
}
