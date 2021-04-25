#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k; int mn = min(m, n / k);
		cout << mn - (m - mn + k - 2) / (k - 1) << '\n';
	}
	return 0;
}
