#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; string n;
	cin >> t;
	while (t--) {
		cin >> n; reverse(n.begin(), n.end());
		int p = 1; vector<int> ans;
		for (char c : n) {
			if (c != '0') ans.push_back((c - '0') * p);
			p *= 10;
		}

		cout << ans.size() << '\n';
		for (int a : ans) cout << a << ' ';
		cout << '\n';
	}
	return 0;
}
