#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << (n == 1 || m == 1 || (n == 2 && m == 2) ? "YES" : "NO") << '\n';
	}
	return 0;
}
