#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int s[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> s[i];
		sort(s, s + n);

		int ans = INT_MAX;
		for (int i = 1; i < n; i++) ans = min(ans, abs(s[i] - s[i - 1]));
		cout << ans << '\n';
	}
	return 0;
}
