#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; string b;
	cin >> t;
	while (t--) {
		cin >> b;
		string ans = string(1, b[0]);
		for (int i = 1; i < int(b.size()); i += 2) ans += b[i];
		cout << ans << '\n';
	}
	return 0;
}
