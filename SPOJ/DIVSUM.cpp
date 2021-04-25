#include <iostream>

using namespace std;

int div_sum(int n)
{
	int sum = 0, i;
	for (i = 1; i * i < n; i++)
	{
		if (n % i == 0)
		{
			sum += i + n / i;
		}
	}

	if (i * i == n) sum += i;
	return sum;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << div_sum(n) - n << "\n";
	}
	return 0;
}
