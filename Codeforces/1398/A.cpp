#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[50000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		if (a[0] + a[1] <= a[n - 1]) cout << "1 2 " << n << '\n';
		else cout << "-1\n";
	}
	return 0;
}
