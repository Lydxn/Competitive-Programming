#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, X, Y, minx = INT_MAX, miny = INT_MAX, maxx = 0, maxy = 0;
	cin >> N;
	while (N--) cin >> X >> Y, minx = min(minx, X), miny = min(miny, Y), maxx = max(maxx, X), maxy = max(maxy, Y);
	cout << max(maxx - minx, maxy - miny) * max(maxx - minx, maxy - miny) << '\n';
	return 0;
}
