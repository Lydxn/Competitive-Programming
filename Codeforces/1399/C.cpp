#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, w, cnt[101];
	cin >> t;
	while (t--) {
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) cin >> w, ++cnt[w];

		int ans = 0;
		for (int i = 2; i <= 2 * n; i++) {
			int cur = 0;
			for (int j = 1; j <= i / 2; j++)
				cur += j == i - j ? cnt[j] / 2 : min(cnt[j], cnt[i - j]);
			ans = max(ans, cur);
		}
		cout << ans << '\n';
	}
	return 0;
}
