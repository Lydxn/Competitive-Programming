#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, a, b, n;
	cin >> T;
	while (T--) {
		cin >> a >> b >> n;
		int cnt = 0;
		while (true) {
			if (a < b) a += b;
			else b += a;
			++cnt;
			if (a > n || b > n) break;
		}
		cout << cnt << '\n';
	}
	return 0;
}
