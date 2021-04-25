#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, D, x, y, px = INT_MAX, py = INT_MAX, ans = 1, cur = 0;
	cin >> N >> D;
	while (N--) {
		cin >> x >> y;
		if ((ll) (px - x) * (px - x) + (py - y) * (py - y) <= D * D) ans = max(ans, ++cur);
		else cur = 0;
		px = x, py = y;
	}
	cout << ans << '\n';
	return 0;
}
