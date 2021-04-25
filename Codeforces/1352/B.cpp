#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;

		if ((n % 2 && k % 2 && n >= k) || (n % 2 == 0 && k % 2 == 0 && n >= k)) {
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++) cout << "1 ";
			cout << n - (k - 1) << '\n';
		} else if (n % 2 == 0 && n >= 2 * k) {
			cout << "YES\n";
			for (int i = 0; i < k - 1; i++) cout << "2 ";
			cout << n - 2 * (k - 1) << '\n';
		} else cout << "NO\n";
	}
	return 0;
}
