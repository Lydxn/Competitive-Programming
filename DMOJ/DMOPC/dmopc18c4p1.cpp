#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, n; double mx, d, sum = 0;
	cin >> K >> mx;

	for (int i = 0; i < K; i++) {
		cin >> n;
		while (n--) cin >> d, sum += d;
		sum += mx;
	}

	cout << fixed << setprecision(4) << sum / K << '\n';
	return 0;
}
