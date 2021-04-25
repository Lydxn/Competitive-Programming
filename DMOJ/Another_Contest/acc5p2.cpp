#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

using namespace std;

const string DMOJ = "DMOJ";

bool is_sequence(string S)
{
	int j = 0;
	for (int i = 0; i < 4 && j < S.size(); i++)
	{
		if (S[j] == DMOJ[i]) ++j;
	}
	return j == S.size();
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S, sub;
	cin >> S;

	int min_cans = 0;
	for (int i = 0; i < S.size(); i++)
	{
		for (int j = 1; j <= S.size() - i; j++)
		{
			sub = S.substr(i, j);
			if (is_sequence(sub))
			{
				min_cans = max(min_cans, j);
			}
		}
	}

	cout << 4 - min_cans << '\n';
	return 0;
}
