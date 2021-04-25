#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a[50];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a, a + n);
		for (int i = 1; i < n; i++) {
			if (a[i] - a[i - 1] > 1) {
				cout << "NO\n";
				goto done;
			}
		}

		cout << "YES\n"; done:;
	}
	return 0;
}
