#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	unordered_set<char> set;
	while (n--)
	{
		set.insert(tolower(s[n]));
	}

	cout << (set.size() == 26 ? "YES" : "NO") << '\n';
	return 0;
}
