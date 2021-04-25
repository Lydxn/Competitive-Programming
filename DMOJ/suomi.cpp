#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, ans = 0, sum = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a;
		a -= M, sum += a;
		if (a < 0) {
			if (sum >= 0) ans -= a;
			else {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
