#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, mx = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		a += mx, mx = max(mx, a);
		cout << a << ' ';
	}
	return 0;
}
