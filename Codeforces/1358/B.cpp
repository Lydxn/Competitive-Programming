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
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] <= i + 1) {
				cout << i + 2 << '\n';
				goto done;
			}
		}
		cout << "1\n"; done:;
	}
	return 0;
}
