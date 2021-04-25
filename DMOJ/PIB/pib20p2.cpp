#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll T;
	cin >> T;

	ll l = 0, r = 1e17, m;
	while (l <= r) {
		m = (l + r) >> 1;
		if (m / 2 - m / 7 <= T) l = m + 1;
		else r = m - 1;
	}

	ll check = r;
    while (check++ < r + 7) {
        if (check / 2 - check / 7 <= T) {
            r = check;
            break;
        }
    }
	cout << r << '\n';
	return 0;
}
