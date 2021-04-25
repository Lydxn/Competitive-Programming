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
		cout << (a % b == 0 ? 0 : b - a % b) << '\n';
	}
	return 0;
}
