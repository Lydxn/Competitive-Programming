#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s; int cur = 1, ans = 1;
	cin >> s;
	for (int i = 1; i < int(s.size()); i++) {
		if (s[i] == s[i - 1]) ++cur;
		else ans = max(ans, cur), cur = 1;
	}
	cout << max(ans, cur) << '\n';
	return 0;
}
