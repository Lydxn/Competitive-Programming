#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[50];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int even = 0, odd = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] % 2) ++odd;
			else ++even;
		}

		sort(a, a + n);
		bool one = false;
		for (int i = 1; i < n; i++) one |= a[i] - a[i - 1] == 1;

		cout << ((even - odd) % 2 || (even % 2 && odd % 2 && !one) ? "NO" : "YES") << '\n';
	}
	return 0;
}
