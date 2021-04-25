#include <iostream>

using namespace std;

int tri[99][99];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, sz;
	cin >> n;

	while (n--)
	{
		cin >> sz;
		for (int i = 0; i < sz; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> tri[i][j];
			}
		}

		for (int i = sz - 2; i >= 0; i--)
		{
			for (int j = i; j >= 0; j--)
			{
				tri[i][j] += tri[i + 1][j + (tri[i + 1][j + 1] > tri[i + 1][j])];
			}
		}

		cout << tri[0][0] << "\n";
	}
	return 0;
}
