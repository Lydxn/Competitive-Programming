#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;

	while (N ^ 1) {
		for (int i = N / 2; i >= 0; i--) {
			if (N % i == 0) {
				ans += (N -= i) / i;
				break;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
