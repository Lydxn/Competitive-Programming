#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> divisors(int n) {
	vector<int> res;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			res.push_back(n / i);
		}
	}

	sort(res.begin(), res.end());
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int d : divisors(n)) {
			if (n / d <= k) {
				cout << d << '\n';
				break;
			}
		}
	}
	return 0;
}
