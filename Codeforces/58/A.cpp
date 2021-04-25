#include <iostream>
#include <set>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int index = 0;
	for (char c : s)
	{
		if (c == "hello"[index]) index++;
	}

	cout << (index == 5 ? "YES" : "NO") << '\n';
	return 0;
}
