#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b; bool parity = a % 2 == b % 2;
		if (a < b) cout << (parity ? 2 : 1) << '\n';
		else if (a > b) cout << (parity ? 1 : 2) << '\n';
		else cout << "0\n";
	}
	return 0;
}
