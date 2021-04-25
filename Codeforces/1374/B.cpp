#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int cnt2 = 0, cnt3 = 0;
		while (n % 2 == 0) n /= 2, ++cnt2;
		while (n % 3 == 0) n /= 3, ++cnt3;
		cout << (n > 1 || cnt2 > cnt3 ? -1 : cnt3 + (cnt3 - cnt2)) << '\n';
	}
	return 0;
}
