#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, mn = INT_MAX, mx = INT_MIN;
	cin >> N;
	while (N--) cin >> a, mn = min(mn, a), mx = max(mx, a);

	cout << mx - mn << '\n';
	return 0;
}
