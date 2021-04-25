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
		cout << count(s.begin() + s.find_first_of('1'), s.begin() + s.find_last_of('1'), '0') << '\n';
	}
	return 0;
}
