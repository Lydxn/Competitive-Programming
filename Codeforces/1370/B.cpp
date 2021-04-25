#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> even, odd;
vector<pii> ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n;

		odd.clear(), even.clear();
		for (int i = 1; i <= 2 * n; i++) {
			cin >> a;
			(a % 2 ? odd : even).push_back(i);
		}

		ans.clear();
		for (int i = 0; i < int(odd.size()) - 1; i += 2) ans.emplace_back(odd[i], odd[i + 1]);
		for (int i = 0; i < int(even.size()) - 1; i += 2) ans.emplace_back(even[i], even[i + 1]);

		for (int i = 0; i < n - 1; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	return 0;
}
