#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string word;
	cin >> word;

	bool space = false;
	for (int i = 0; i < word.size(); i++)
	{
		if (word.substr(i, 3) == "WUB")
		{
			if (space) putchar(' ');
			space = false;
			i += 2;
		}
		else
		{
			putchar(word[i]);
			space = true;
		}
	}
	return 0;
}
