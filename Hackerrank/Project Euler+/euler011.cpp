#include <algorithm>
#include <iostream>

using namespace std;

const int SZ = 20;
int grid[SZ][SZ];

int max_prod(int xl, int xr, int yl, int yr, int dirx, int diry)
{
	int maxp = 0, prod;
	for (int i = yl; i < yr; i++)
	{
		for (int j = xl; j < xr; j++)
		{
			prod = 1;
			for (int k = 0; k < 4; k++)
			{
				prod *= grid[diry == 1 ? j + k : diry == -1 ? j - k : j]
							[dirx == 1 ? i + k : dirx == -1 ? i - k : i];
			}
			maxp = max(maxp, prod);
		}
	}
	return maxp;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cin >> grid[i][j];
		}
	}

	cout <<
		max(max(max_prod(0, 20, 0, 17, 1, 0), max_prod(0, 17, 0, 20, 0, 1)),
			max(max_prod(0, 17, 3, 20, -1, 1), max_prod(0, 17, 0, 17, 1, 1))) << '\n';
}
