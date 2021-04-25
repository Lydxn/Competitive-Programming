#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, X, Y, x, y, m, mx, my, mm = INT_MAX;
	cin >> R >> X >> Y;

	for (int i = 0; i < 3; i++) {
		cin >> x >> y >> m;
		if (m < mm) mm = m, mx = x, my = y;
	}

	cout << (sqrt((X - mx) * (X - mx) + (Y - my) * (Y - my)) < R ? "What a beauty!" : "Time to move my telescope!") << '\n';
	return 0;
}
