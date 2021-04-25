#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);

		for (int i = (n + 1) / 2 - 1, j = i + 1; i >= 0; i--, j++) {
			if (i >= 0) cout << a[i] << ' ';
			if (j < n) cout << a[j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
