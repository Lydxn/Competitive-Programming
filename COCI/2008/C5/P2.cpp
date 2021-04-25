#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, G;
	cin >> R >> G;

	for (int i = 1, x = __gcd(R, G); i * i <= x; i++) {
		if (x % i == 0) {
			cout << i << ' ' << R / i << ' ' << G / i << '\n';
			int j = x / i;
			if (j != i) cout << j << ' ' << R / j << ' ' << G / j << '\n';
		}
	}
	return 0;
}
