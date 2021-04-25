#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; ll a, b, c, d;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;
		cout << (a <= b ? b : d >= c ? -1 : b + (a - b + c - d - 1) / (c - d) * c) << '\n';
	}
	return 0;
}
