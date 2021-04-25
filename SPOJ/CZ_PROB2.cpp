#include <iostream>

using namespace std;

long long div_sum(int n)
{
	long long res = 1, sum, term;
	for (int i = 2; i * i <= n; i++)
	{
		sum = 1, term = 1;
		while (n % i == 0)
		{
			n /= i;
			term *= i;
			sum += term;
		}
		res *= sum;
	}

	if (n >= 2) res *= n + 1;
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, n;
	cin >> T;

	while (T--)
	{
		cin >> n;
		cout << div_sum(n) << "\n";
	}
	return 0;
}
