#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int mn[5001], mx[5001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n; memset(mn, 0x3f, sizeof(mn)); memset(mx, 0, sizeof(mx));
		for (int i = 1; i <= n; i++) cin >> a, mn[a] = min(mn[a], i), mx[a] = max(mx[a], i);

		for (int i = 1; i <= n; i++) {
			if (mn[i] + 1 < mx[i]) {
				cout << "YES\n";
				goto done;
			}
		}
		cout << "NO\n"; done:;
	}
	return 0;
}
