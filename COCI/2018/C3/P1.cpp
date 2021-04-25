#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	bool h = false, o = false, n = false;
	int ans = 0;
	for (char c : s) {
		if (c == 'H') h = true;
		if (c == 'O' && h) o = true;
		if (c == 'N' && o) n = true;
		if (c == 'I' && n) ++ans, h = o = n = false;
	}
	cout << ans << '\n';
	return 0;
}
