#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, lr = 0, rl = 0;
	cin >> n;

	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		lr += arr[i][i];
		rl += arr[i][n - i - 1];
	}

	cout << abs(lr - rl) << '\n';
	return 0;
}
