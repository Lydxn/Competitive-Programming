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
		if (n == 1) cout << "-1\n";
		else cout << "5" + string(n - 1, '3') << '\n';
	}
	return 0;
}
