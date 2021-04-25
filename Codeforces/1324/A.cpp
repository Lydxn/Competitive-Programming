#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n; int par = 0;
		for (int i = 0; i < n; i++) cin >> a, par += a % 2 ? 1 : -1;
		cout << (par == n || par == -n ? "YES" : "NO") << '\n';
	}
	return 0;
}
