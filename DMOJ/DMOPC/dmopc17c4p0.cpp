#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	cout << min((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), min((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3), (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2))) << '\n';
	return 0;
}
