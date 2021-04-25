#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

long double d[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n; string name;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> name >> d[i];

	sort(d, d + n); long double ans = DBL_MAX;
	for (int i = 0; i < n; i++) {
		long double s = d[i], e = d[(i - 1 + n) % n];
		ans = min(ans, s <= e ? e - s : 360 - s + e);
	}
	cout << ceil(ans / 360 * 72 * 60) << '\n';
	return 0;
}
