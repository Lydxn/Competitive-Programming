#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int ans[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, t, w;
	cin >> N;
	while (N--) {
		cin >> t >> w;
		ans[t] = max(ans[t], w);
	}
	for (int i = 0; i <= 1000000; i++) ans[i] = max(ans[i], ans[i - 1]);

	cin >> Q;
	while (Q--) {
		cin >> t;
		cout << ans[t] << '\n';
	}
	return 0;
}
