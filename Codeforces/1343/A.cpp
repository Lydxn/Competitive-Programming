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
		for (int i = 2; i <= 30; i++) {
			int p = (1 << i) - 1;
			if (n % p == 0) {
				cout << n / p << '\n';
				break;
			}
		}
	}
	return 0;
}
