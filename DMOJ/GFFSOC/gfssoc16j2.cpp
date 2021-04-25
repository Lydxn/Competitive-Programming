#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int g0, g1, g2, g3, g4, g5, s, r;
	cin >> g0 >> g1 >> g2 >> g3 >> g4 >> g5 >> s >> r;
	cout << ((g0 + g1 + g2 + g3 + g4 + g5) / 6.0 + s >= r ? "yes" : "no") << '\n';
	return 0;
}
