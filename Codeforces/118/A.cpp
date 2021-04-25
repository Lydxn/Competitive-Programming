#include <iostream>
#include <string>

using namespace std;

const string vowels = "AEIOUY";

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	for (char c : str)
	{
		if (vowels.find(toupper(c)) == string::npos)
		{
			cout << '.' << char(tolower(c));
		}
	}

	putchar('\n');
	return 0;
}
