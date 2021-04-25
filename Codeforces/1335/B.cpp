#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		string cycle = string(a - b + 1, 'a');
		for (int i = 0; i < b - 1; i++) cycle.push_back(char(i + 'b'));

		string res = "";
		while (true) {
			for (char c : cycle) {
				res.push_back(c);
				if (int(res.size()) == n) goto done;
			}
		}

		done:;
		cout << res << '\n';
	}
	return 0;
}
