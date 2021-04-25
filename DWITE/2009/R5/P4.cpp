#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string letter[5] = {"xx.x", "xxxx", "xx.xxx", "x.xx", "x.xxxx"};

string solve(string s) {
	if (s.empty()) return "";
	for (int i = 0; i < 5; i++) {
		if (s.substr(0, letter[i].size()) == letter[i]) {
			string nxt = solve(s.substr(letter[i].size()));
			if (nxt != "BAD") return char('A' + i) + nxt;
		}
	}
	return "BAD";
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s1, s2, s;
	for (int _ = 0; _ < 5; _++) {
		cin >> s1 >> s2; s = "";
		for (int i = 0; i < int(s1.size()); i++) s += string(1, s1[i]) + string(1, s2[i]);
		cout << solve(s) << '\n';
	}
	return 0;
}
