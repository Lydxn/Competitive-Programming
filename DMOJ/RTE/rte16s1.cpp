#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, K;
	cin >> T;

	while (T--) {
		cin >> N >> K;
		int rest = N - K, tri = 1, ans = 0;
		while (ans <= rest) ans += tri * (tri + 1) / 2, ++tri;
		cout << ans - tri * (tri - 1) / 2 << '\n';
	}
	return 0;
}
