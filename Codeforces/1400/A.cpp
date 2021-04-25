#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n; string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		cout << string(n, s[s.size() / 2])  << '\n';
	}
	return 0;
}
