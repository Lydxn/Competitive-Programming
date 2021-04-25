#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> dict;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string word;
	for (int i = 0; i < N; i++)
	{
		cin >> word;
		dict.insert(word);
	}

	while (cin >> word)
	{
		if (dict.find(word) == dict.end())
		{
			cout << "Incorrect\n";
			return 0;
		}
	}

	cout << "Correct\n";
	return 0;
}
