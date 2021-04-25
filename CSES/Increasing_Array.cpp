#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int x[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, mx = 0; ll ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) ans += max(0, mx - x[i]), mx = max(mx, x[i]);
	cout << ans << '\n';
	return 0;
}
