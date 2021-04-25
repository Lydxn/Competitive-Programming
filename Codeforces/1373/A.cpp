#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; ll a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		cout << (a < c ? 1 : -1) << ' ' << (c < a * b ? b : -1) << '\n';
	}
	return 0;
}
