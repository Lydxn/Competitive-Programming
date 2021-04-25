#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b; int mn = min(a, b), mx = max(a, b);
		cout << pow(max(mn * 2, mx), 2) << '\n';
	}
	return 0;
}
