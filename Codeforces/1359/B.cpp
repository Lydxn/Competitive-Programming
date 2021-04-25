#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m, x, y; string line;
	cin >> t;
	while (t--) {
		cin >> n >> m >> x >> y;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> line;
			if (x * 2 <= y) sum += count(line.begin(), line.end(), '.') * x;
			else {
				for (int i = 0, len = line.size(); i < len; i++) {
					if (line[i] == '.') {
						if (i != len - 1 && line[i + 1] == '.') sum += y, ++i;
						else sum += x;
					}
				}
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
