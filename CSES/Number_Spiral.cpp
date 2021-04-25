#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, y, x;
	cin >> t;
	while (t--) {
		cin >> y >> x;
		ll layer = max(x, y);
		if (layer % 2 == 0) swap(x, y);
		cout << (layer - 1) * (layer - 1) + x + (layer - y) << '\n';
	}
	return 0;
}
