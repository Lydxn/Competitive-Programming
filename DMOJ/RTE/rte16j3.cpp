#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int lost[1001], cnt[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, C, n, x; string op;
	cin >> T;
	while (T--) {
		memset(lost, false, sizeof(lost));
		memset(cnt, 0, sizeof(cnt));

		cin >> N >> C;
		while (C--) {
			cin >> op;
			switch (op[0]) {
				case 'A':
					cin >> n >> x;
					if (!lost[x]) cnt[x] += n;
					break;
				case 'Q':
					cin >> x;
					cout << cnt[x] << '\n';
					break;
				case 'G': {
					cin >> x; int ans = 0;
					for (int i = 1; i <= x; i++) ans += cnt[i];
					cout << ans << '\n';
					break;
				}
				case 'L': {
					cin >> x; int ans = 0;
					for (int i = N; i > N - x; i--) ans += cnt[i];
					cout << ans << '\n';
					break;
				}
				default:
					cin >> x;
					lost[x] = true, cnt[x] = 0;
					break;
			}
		}
	}
	return 0;
}
