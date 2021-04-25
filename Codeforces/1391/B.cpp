#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m; char a;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a;
				cnt += (i == n - 1 && a == 'D') || (j == m - 1 && a == 'R');
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
