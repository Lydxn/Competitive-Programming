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
		cin >> a >> b;
		cout << min(min(a, b), (a + b) / 3) << '\n';
	}
	return 0;
}
