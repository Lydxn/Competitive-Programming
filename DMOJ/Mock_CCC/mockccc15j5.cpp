#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii xs[100000], ys[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, x, y, xp = INT_MAX, yp = INT_MAX; ll ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> x >> y, xs[i] = {x, y}, ys[i] = {y, x};
	sort(xs, xs + N); sort(ys, ys + N);

	cin >> M;
	while (M--) {
		cin >> x >> y;
		if (x == xp) ans += upper_bound(xs, xs + N, make_pair(x, max(y, yp))) - lower_bound(xs, xs + N, make_pair(x, min(y, yp)));
		if (y == yp) ans += upper_bound(ys, ys + N, make_pair(y, max(x, xp))) - lower_bound(ys, ys + N, make_pair(y, min(x, xp)));
		xp = x, yp = y;
	}

	cout << ans << '\n';
	return 0;
}
