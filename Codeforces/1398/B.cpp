#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T; string s;
	cin >> T;
	while (T--) {
		cin >> s; s.push_back('0');
		vector<int> v;
		int cur = 0;

		for (char c : s) {
			if (c == '1') ++cur;
			else if (cur > 0) v.push_back(cur), cur = 0;
		}

		sort(v.begin(), v.end(), greater<int>());
		int ans = 0;
		for (int i = 0; i < int(v.size()); i += 2) ans += v[i];
		cout << ans << '\n';
	}
	return 0;
}
