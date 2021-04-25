#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int elem;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> elem;
			if (elem)
			{
				cout << abs(i - 3) + abs(j - 3);
				return 0;
			}
		}
	}
}
