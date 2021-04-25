#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool ca[1001], cb[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(ca, false, sizeof(ca)), memset(cb, false, sizeof(cb));

		for (int i = 0; i < n; i++) cin >> a, ca[a] = true;
		for (int i = 0; i < m; i++) cin >> b, cb[b] = true;

		for (int i = 0; i <= 1000; i++) {
			if (ca[i] && cb[i]) {
				cout << "YES\n1 " << i << '\n';
				goto done;
			}
		}
		cout << "NO\n"; done:;
	}
	return 0;
}
