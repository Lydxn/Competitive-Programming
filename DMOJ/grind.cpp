#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXT = 10000001;
int diff[MAXT];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, s, f, ans = 0;
	cin >> N;
	while (N--) {
		cin >> s >> f;
		++diff[s], --diff[f];
	}

	for (int i = 1, p = 0; i < MAXT; i++) p += diff[i], ans = max(ans, p);
	cout << ans << '\n';
	return 0;
}
