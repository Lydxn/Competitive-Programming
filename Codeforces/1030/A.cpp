#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n, diff;
	cin >> n;

	bool easy = true;
	while (n--)
	{
		cin >> diff;
		if (diff)
		{
			easy = false;
			break;
		}
	}

	cout << (easy ? "EASY" : "HARD") << '\n';
	return 0;
}
