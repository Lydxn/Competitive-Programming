#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, x, a;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		int even = 0, odd = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a % 2) ++odd;
			else ++even;
		}

		bool ans = false;
		for (int i = 1; i <= odd; i += 2) ans |= i <= x && x - i <= even;
		cout << (ans ? "YES" : "NO") << '\n';
	}
	return 0;
}
