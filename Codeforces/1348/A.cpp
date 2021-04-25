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
		int l = 1 << n;
		for (int i = 1; i < n / 2; i++) l |= 1 << i;
		cout << l - ((1 << (n + 1)) - 2 - l) << '\n';
	}
	return 0;
}
