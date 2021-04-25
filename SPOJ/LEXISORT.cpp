#include <algorithm>
#include <iostream>

using namespace std;

string strs[50000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k;

	while (k--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> strs[i];
		}

		sort(strs, strs + n);
		for (int i = 0; i < n; i++)
		{
			cout << strs[i] << "\n";
		}
	}
	return 0;
}
