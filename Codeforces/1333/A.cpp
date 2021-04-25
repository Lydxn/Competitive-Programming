#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << "W" + string(m - 1, 'B') << '\n';
		for (int i = 1; i < n; i++) cout << string(m, 'B') << '\n';
	}
	return 0;
}
