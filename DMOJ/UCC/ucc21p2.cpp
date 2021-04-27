#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, cur = 0, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (a % 2 == 0) cur += a;
		else cur = 0;
		ans = max(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}