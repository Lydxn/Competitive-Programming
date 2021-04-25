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
		cin >> n; n >>= 1;
		cout << (ll) n * (n + 1) * (2 * n + 1) / 6 * 8 << '\n';
	}
	return 0;
}
