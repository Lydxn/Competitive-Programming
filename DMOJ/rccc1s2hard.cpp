#include <algorithm>
#include <iostream>

using namespace std;

int a[7000], cnt[256], pidx;
long long p[49000000];

int main() {
	int N; long long ans1 = 0, ans2 = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			p[pidx++] = 1LL * a[i] * a[j];
	sort(p, p + pidx);
	for (int i = 1, x = 0; i <= pidx; i++)
		if (p[i] == p[i - 1]) ++x;
		else ans1 += 1LL * x * (x + 1), x = 0;
	sort(a, a + N);
	for (int i = 1, x = 0; i <= N; i++)
		if (a[i] == a[i - 1]) ++x;
		else ans2 += 1LL * x * (x + 1), x = 0;
	cout << ((ans1 - ans2 * (N - 2)) << 2) << '\n';
	return 0;
}