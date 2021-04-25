#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, s;
	cin >> t;
	while (t--) {
		cin >> s; int ans = 0, lg;
		while (s) lg = pow(10, int(log10(s))), ans += lg, s = s - lg + lg / 10;
		cout << ans << '\n';
	}
	return 0;
}
