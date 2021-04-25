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
		if (n > 30) {
			if (n - 30 == 6 || n - 30 == 10 || n - 30 == 14) cout << "YES\n6 10 15 " << n - 31 << '\n';
			else cout << "YES\n6 10 14 " << n - 30 << '\n';
		} else cout << "NO\n";
	}
	return 0;
}
