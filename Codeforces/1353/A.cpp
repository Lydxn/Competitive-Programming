#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << (n > 2 ? m * 2 : n > 1 ? m : 0) << '\n';
	}
	return 0;
}
