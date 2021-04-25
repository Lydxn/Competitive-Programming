#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n; int sum = 0; bool even = false, odd = false;
		while (n--) cin >> a, sum += a, even |= !(a % 2), odd |= a % 2;
		cout << (sum % 2 || (even && odd) ? "YES" : "NO") << '\n';
	}
	return 0;
}
