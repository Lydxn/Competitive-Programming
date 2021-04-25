#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	double N, n, a, b, t;
	cin >> N;

	while (N--) {
		cin >> n >> a >> b >> t;
		int ans = ceil((t + n * b) / (a + b));
		cout << (ans > n ? -1 : ans) << '\n';
	}
	return 0;
}
