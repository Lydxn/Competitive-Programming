#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<int, int> cnt;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n; cnt.clear();
		for (int i = 0; i < n; i++) cin >> a, ++cnt[a];

		int mx = 0;
		for (auto c : cnt) mx = max(mx, c.second);
		cout << max(min(int(cnt.size()) - 1, mx), min(int(cnt.size()), mx - 1)) << '\n';
	}
	return 0;
}
