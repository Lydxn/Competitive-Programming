#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	s.erase(remove(s.begin(), s.end(), '+'), s.end());
	sort(s.begin(), s.end());

	for (int i = 0; i < s.size(); i++)
	{
		if (i) putchar('+');
		putchar(s[i]);
	}
	return 0;
}
