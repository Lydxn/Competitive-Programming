#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int lower = 0;
	for (char c : s)
	{
		if (islower(c)) lower++;
		else lower--;
	}

	transform(s.begin(), s.end(), s.begin(), lower >= 0 ? ::tolower : ::toupper);
	cout << s << '\n';
	return 0;
}
