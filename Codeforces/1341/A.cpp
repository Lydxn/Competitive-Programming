#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a, b, c, d;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b >> c >> d; int l = (a - b) * n, r = (a + b) * n;
		cout << (l <= c + d && r >= c - d ? "Yes" : "No") << '\n';
	}
	return 0;
}
