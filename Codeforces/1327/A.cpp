#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; ll n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << (n % 2 == k % 2 && k * k <= n ? "YES" : "NO") << '\n';
	}
	return 0;
}
