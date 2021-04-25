#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int diff[100002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, y, sum = 0, ans = 0;
	cin >> N >> Q;

	while (Q--) {
		cin >> x >> y;
		++diff[x], --diff[y];
	}

	for (int i = 0; i < N; i++) sum += diff[i], ans += sum > 0;
	cout << N - ans << ' ' << ans << '\n';
	return 0;
}
