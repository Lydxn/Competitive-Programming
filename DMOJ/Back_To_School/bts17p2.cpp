#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int G, e, p; double prob = 1;
	cin >> G;
	while (G--) cin >> e >> p, prob *= (double) (p - e) / p;

	cout << prob << '\n';
	return 0;
}
