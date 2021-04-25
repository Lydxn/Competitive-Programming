#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, a[3];
	cin >> t;
	while (t--) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		if (a[1] == a[2]) cout << "YES\n" << a[0] << ' ' << a[0] << ' ' << a[2] << '\n';
		else cout << "NO\n";
	}
	return 0;
}
