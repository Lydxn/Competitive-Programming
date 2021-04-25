#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	pii w[4];
	for (int i = 0; i < 4; i++) cin >> w[i].first, w[i].second = i;
	sort(w, w + 4);
	cout << (abs(w[3].second - w[2].second) == 2 ? "trans" : "cis") << '\n';
	return 0;
}
