#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, t, a = 0, b = 0, c = 0, d = 0, e = 0, cf = 0, f = 0;
	double S;
	cin >> N >> S;

	while (N--) {
		cin >> t; t = abs(t), ++cf;
		if (0 <= t && t <= 50) ++a;
		else if (51 <= t && t <= 100) ++b;
		else if (101 <= t && t <= 150) ++c;
		else if (151 <= t && t <= 200) ++d;
		else ++e, cf = 0;
		f = max(f, cf);
	}
	cout << fixed << setprecision(1) << max(0.0, 1.5 * a + b + c + 0.5 * d - e + 0.5 * f - S) << '\n';
	return 0;
}
