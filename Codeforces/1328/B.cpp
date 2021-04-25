#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		string res = string(n, 'a');

		int sum = 0, x = 1;
		for (; sum < k; x++) sum += x;
		res[n - x] = res[n - x + sum - k + 1] = 'b';
		cout << res << '\n';
	}
	return 0;
}
