#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int f(int n) {
	int res = 0;
	for (int i = 2; res + i <= n; i += 3) res += i;
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int cnt = 0;
		while (n > 1) n -= f(n), ++cnt;
		cout << cnt << '\n';
	}
	return 0;
}
