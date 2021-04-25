#include <iostream>

using namespace std;

int sizes[4];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n;

	while (n--)
	{
		cin >> s;
		sizes[s - 1]++;
	}

	int taxis = sizes[3] + sizes[2] + sizes[1] / 2;
	if (sizes[1] % 2)
	{
		taxis++;
		sizes[0] -= 2;
	}

	if ((sizes[0] -= sizes[2]) > 0)
	{
		taxis += (sizes[0] + 3) / 4;
	}

	cout << taxis << '\n';
	return 0;
}
