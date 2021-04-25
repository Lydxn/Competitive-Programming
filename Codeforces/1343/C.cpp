#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		ll sum = 0, i = 0;
		while (i < n) {
			int cur = INT_MIN, j = i;
			while (j < n && (a[i] > 0) == (a[j] > 0)) cur = max(cur, a[j++]);
			sum += cur, i = j;
		}
		cout << sum << '\n';
	}
	return 0;
}
