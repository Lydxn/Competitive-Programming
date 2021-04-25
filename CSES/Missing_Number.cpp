#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n, sum = 0;
	cin >> n;
	for (int i = 0, x; i < n - 1; i++) cin >> x, sum += x;
	cout << n * (n + 1) / 2 - sum << '\n';
	return 0;
}
