#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (c != 0) {
		if (a == 0 && b == 0 && c == 1 && d == 1) cout << "C2H2\n";
		else cout << "invalid\n";
	} else if (b != 0) {
		if (a == 0 && c == 0 && d == 4) cout << "C" << b + 1 << "H4\n";
		else cout << "invalid\n";
	} else if (a != 0) {
		if (b == 0 && c == 0 && d == 2 * (a + 2)) cout << "C" << a + 1 << "H" << 2 * (a + 2) << '\n';
		else cout << "invalid\n";
	} else {
		if (d == 4) cout << "C1H4\n";
		else cout << "invalid\n";
	}
	return 0;
}
