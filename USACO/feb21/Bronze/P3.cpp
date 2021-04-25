#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string S;
	cin >> N;
	while (N--) {
		cin >> S; char c;
		int x = 0, y = 0, px = 0, py = 0, ans = 0;
		for (int i = 0; i < int(S.size()); i++) {
			c = S[i];
			if (c == 'N') ++y;
			if (c == 'E') ++x;
			if (c == 'S') --y;
			if (c == 'W') --x;
			ans += (x - px) * (y + py);
			px = x, py = y;
		}
		cout << (ans > 0 ? "CW" : "CCW") << '\n';
	}
	return 0;
}
