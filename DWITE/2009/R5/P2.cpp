#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	for (int _ = 0; _ < 5; _++) {
		cin >> N;
		bool g0 = false, g1 = false; int ans = -1;
		for (int i = 1; ; i++) {
			if (is_prime(N + i)) {
				if (g0) {
					ans = N + i;
					break;
				}
				g0 = true;
			}
			if (is_prime(N - i)) {
				if (g1) {
					ans = N - i;
					break;
				}
				g1 = true;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
