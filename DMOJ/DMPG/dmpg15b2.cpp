#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t0[3], t1[3];
	cin >> t0[0] >> t0[1] >> t0[2] >> t1[0] >> t1[1] >> t1[2];

	sort(t0, t0 + 3); sort(t1, t1 + 3);
	bool flag = true;
	for (int i = 0; i < 3; i++) flag &= t0[i] <= t1[i];
	cout << (flag ? 'Y' : 'N') << '\n';
	return 0;
}
