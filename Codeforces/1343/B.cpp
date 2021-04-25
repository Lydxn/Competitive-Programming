#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n % 4) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		for (int i = 2; i <= n; i += 2) cout << i << ' ';
		for (int i = 1; i < n - 1; i += 2) cout << i << ' ';
		cout << n + n / 2 - 1 << '\n';
	}
	return 0;
}
