#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t; string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int cnt = count(s.begin(), s.end(), '0');
		cout << (min(cnt, int(s.size()) - cnt) % 2 ? "DA" : "NET") << '\n';
	}
	return 0;
}
