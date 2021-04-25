#include <iostream>

using namespace std;

int h[30], a[30];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> h[i] >> a[i];

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && h[i] == a[j]) count++;
		}
	}

	cout << count << '\n';
	return 0;
}
