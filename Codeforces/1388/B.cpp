#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << string(n - (n + 3) / 4, '9') << string((n + 3) / 4, '8') << '\n';
	}
	return 0;
}
