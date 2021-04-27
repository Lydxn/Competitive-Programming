#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < int(s.size()); i++) {
		if (s[i] == '2' && (i == int(s.size()) - 1 || s[i + 1] != '5')) ++cnt;
	}
	cout << cnt << '\n';
	return 0;
}