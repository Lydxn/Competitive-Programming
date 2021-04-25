#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a, vis[51];
	cin >> t;
	while (t--) {
		memset(vis, false, sizeof(vis));

		cin >> n;
		for (int i = 0; i < n << 1; i++) {
			cin >> a;
			if (!vis[a]) cout << a << ' ';
			vis[a] = true;
		}
		cout << '\n';
	}
	return 0;
}
