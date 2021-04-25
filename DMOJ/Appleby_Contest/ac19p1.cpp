#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll T, N, A, B, C;
	cin >> T;

	while (T--) {
		cin >> N >> A >> B >> C;
		if (A + B + C < N) cout << "-1\n";
		else {
			ll A1 = max(0LL, N - C - B), B1 = max(0LL, N - A1 - C), C1 = N - B1 - A1;
			cout << A1 << ' ' << B1 << ' ' << C1 << '\n';
		}
	}
	return 0;
}
