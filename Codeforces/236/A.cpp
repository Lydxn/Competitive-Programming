#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	unordered_set<char> letters(str.begin(), str.end());
	cout << (letters.size() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!") << '\n';
	return 0;
}
