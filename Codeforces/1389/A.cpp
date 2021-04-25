#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, l, r;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		if (l * 2 <= r) cout << l << ' ' << l * 2 << '\n';
		else cout << "-1 -1\n";
	}
	return 0;
}
