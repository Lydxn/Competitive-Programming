#include <bits/stdc++.h>

using namespace std;

struct point {
	int a, b, d;
	point() {}
	point(int a, int b, int d) : a(a), b(b), d(d) {}
	bool operator< (const point& p) { return d < p.d; }
};

const int MAXN = 2001;
point p[4000000];
int x[MAXN], y[MAXN], dp[MAXN], pdp[MAXN], pd[MAXN], pi;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			p[pi++] = point(i, j, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
		}
	}
	sort(p, p + pi);

	for (int i = 0; i < pi; i++) {
		int a = p[i].a, b = p[i].b, d = p[i].d;
		if (d != pd[a]) pd[a] = d, pdp[a] = dp[a];
		if (d != pd[b]) pd[b] = d, pdp[b] = dp[b];

		if (a == 0) dp[a] = max(dp[a], pdp[b]);
		else dp[a] = max(dp[a], pdp[b] + 1), dp[b] = max(dp[b], pdp[a] + 1);
	}

	cout << dp[0] + 1 << '\n';
	return 0;
}
