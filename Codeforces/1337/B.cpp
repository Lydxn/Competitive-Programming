#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, x, m, n;
	cin >> t;
	while (t--) {
		cin >> x >> n >> m;
		while (n-- && x / 2 + 10 < x) x = x / 2 + 10;
		cout << (x - m * 10 <= 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}
