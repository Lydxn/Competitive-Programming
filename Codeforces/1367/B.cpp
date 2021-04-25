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
		cin >> n;

		int bad = 0, par = 0;
		for (int i = 0; i < n; i++) cin >> a, bad += a % 2 != i % 2, par += a % 2 ? 1 : -1;
		cout << (par + n % 2 ? -1 : bad / 2) << '\n';
	}
	return 0;
}
