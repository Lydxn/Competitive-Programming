#include <iostream>

using namespace std;

string bus[1000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	bool is_pair = false;
	for (int i = 0; i < n; i++)
	{
		cin >> bus[i];
		if (!is_pair)
		{
			if (bus[i].substr(0, 2) == "OO")
			{
				bus[i].replace(0, 2, "++");
				is_pair = true;
			}
			else if (bus[i].substr(3, 5) == "OO")
			{
				bus[i].replace(3, 5, "++");
				is_pair = true;
			}
		}
	}

	if (is_pair)
	{
		cout << "YES\n";
		for (int i = 0; i < n; i++) cout << bus[i] << '\n';
	}
	else cout << "NO\n";
	return 0;
}
