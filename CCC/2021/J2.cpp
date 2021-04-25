#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, mx = 0; string S, ans;
	cin >> N;
	while (N--) {
		cin >> S >> x;
		if (x > mx) mx = x, ans = S;
	}
	cout << ans << '\n';
	return 0;
}