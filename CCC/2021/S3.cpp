#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
ll P[200001], W[200001], D[200001];

ll f(int x) {
	ll res = 0;
	for (int i = 0; i < N; i++) {
		ll y = W[i] * (abs(P[i] - x) - D[i]);
		if (y > 0) res += y;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i] >> W[i] >> D[i];
	int l = 0, r = 1e9, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (f(mid) < f(mid + 1)) r = mid;
		else l = mid + 1;
	}
	cout << f(l) << '\n';
	return 0;
}