#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int p[101], c[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> p[i] >> c[i];

		for (int i = 1; i <= n; i++) {
			if (p[i] < p[i - 1] || c[i] < c[i - 1] || p[i] - p[i - 1] < c[i] - c[i - 1]) {
				cout << "NO\n";
				goto done;
			}
		}
		cout << "YES\n"; done:;
	}
	return 0;
}
