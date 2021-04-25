#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int i = 2;
		for (; i <= n; i++)
			if (n % i == 0) break;

		cout << n + i + (k - 1) * 2 << '\n';
	}
	return 0;
}
