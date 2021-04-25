#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, x, y;
	cin >> n >> a >> x >> b >> y;

	--a, --b, --x, --y;
	while (true) {
		if (a == b) {
			cout << "YES\n";
			return 0;
		}
		if (a == x || b == y) break;
		a = (a + 1) % n, b = (b - 1 + n) % n;
	}
	cout << "NO\n";
	return 0;
}
