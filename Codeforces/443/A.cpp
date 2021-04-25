#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	getline(cin, s);

	unordered_set<char> set;
	for (int i = 1; i < s.size(); i += 3) set.insert(s[i]);

	cout << (s == "{}" ? 0 : set.size()) << '\n';
	return 0;
}
