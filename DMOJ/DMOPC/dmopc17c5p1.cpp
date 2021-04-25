#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	unordered_map<char, char> mp = {{'0', 'O'}, {'1', 'l'}, {'3', 'E'}, {'4', 'A'}, {'5', 'S'}, {'6', 'G'}, {'8', 'B'}, {'9', 'g'}};
	for (char ch : s) cout << (mp.count(ch) ? mp[ch] : ch);
	return 0;
}
