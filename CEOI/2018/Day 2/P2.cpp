#include <bits/stdc++.h>

using namespace std;

set<int> ans;

void solve(int n, int sum, int lim) {
	ans.insert(sum + n - 1);
	for (int i = lim; i * i <= n; i++)
		if (n % i == 0)
			solve(n / i, sum + i - 1, i);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	solve(n, 0, 2);

	cout << ans.size() << '\n';
	for (int a : ans) cout << a << ' ';
	cout << '\n';
	return 0;
}
