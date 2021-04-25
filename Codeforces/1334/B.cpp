#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, n, x;
	cin >> T;
	while (T--) {
		cin >> n >> x;
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a, a + n, greater<int>()); ll idx = 0, sum = 0;
		for (; idx < n; idx++) {
			sum += a[idx];
			if (sum < x * (idx + 1)) break;
		}
		cout << idx << '\n';
	}
	return 0;
}
