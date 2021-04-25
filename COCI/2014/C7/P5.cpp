#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, K, a[1000000];
double p[1000001];

bool search(double x) {
	p[0] = 0;
	for (int i = 1; i <= N; i++) p[i] = p[i - 1] + a[i - 1] - x;

	double mn = 0;
	for (int i = K; i <= N; i++) {
		if (p[i] > mn) return true;
		mn = min(mn, p[i - K + 1]);
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> a[i];

	double l = 0, r = 1e6, mid;
	while (r - l > 1e-6) {
		mid = (l + r) / 2;
		if (search(mid)) l = mid;
		else r = mid;
	}

	cout << fixed << setprecision(6) << l << '\n';
	return 0;
}
