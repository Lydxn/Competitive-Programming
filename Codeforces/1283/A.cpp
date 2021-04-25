#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, h, m;
	cin >> t;
	while (t--) {
		cin >> h >> m;
		cout << 60 * (23 - h) + (60 - m) << '\n';
	}
	return 0;
}
