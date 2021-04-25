#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;

	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	sort(a.begin(), a.end(), greater<int>());
	while (!a.empty()) {
		bool first = true;
		for (int i = 0, prev = -1; i < int(a.size()); i++) {
			if (a[i] != prev) {
				prev = a[i];
				if (first) ans += a[i], first = false;
				a.erase(a.begin() + i--);
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
