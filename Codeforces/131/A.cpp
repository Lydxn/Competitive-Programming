#include <iostream>
#include <string>

using namespace std;

bool is_upper(string str)
{
	for (char c : str)
	{
		if (islower(c)) return false;
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string word;
	cin >> word;

	if (is_upper(word.substr(1, word.size() - 1)))
	{
		for (int i = 0; i < word.size(); i++)
		{
			word[i] ^= 32;
		}
	}

	cout << word << '\n';
	return 0;
}
