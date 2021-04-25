#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++)
		cout << (i - 1) * (i + 4) * (i * i - 3 * i + 4) / 2 << '\n'; // A172132
	return 0;
}
