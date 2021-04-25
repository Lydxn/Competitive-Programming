#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, c;
	long long sum_a = 0, sum_b = 0, sum_c = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sum_a += a;
	}

	for (int i = 0; i < n - 1; i++)
	{
		cin >> b;
		sum_b += b;
	}

	for (int i = 0; i < n - 2; i++)
	{
		cin >> c;
		sum_c += c;
	}

	cout << sum_a - sum_b << '\n'
		 << sum_b - sum_c << '\n';
	return 0;
}
