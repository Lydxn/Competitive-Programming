#include <algorithm>
#include <iostream>

using namespace std;

int a[100], dp[100];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, bit, max_sum, count = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> bit;
		if (bit) a[i] = -1, ++count;
		else	  a[i] = 1;
	}

	max_sum = dp[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		max_sum = max(max_sum, dp[i] = max(dp[i - 1] + a[i], a[i]));
	}

	cout << max_sum + count << '\n';
	return 0;
}
