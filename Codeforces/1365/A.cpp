#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_set<int> sr, sc;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, m, a;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		sr.clear(), sc.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a;
				if (a) sr.insert(i), sc.insert(j);
			}
		}
		cout << (min(n - sr.size(), m - sc.size()) % 2 ? "Ashish" : "Vivek") << '\n';
	}
	return 0;
}
