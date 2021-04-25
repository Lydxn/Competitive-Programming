#include <iostream>

using namespace std;

bool is_prime(int N)
{
	if (N == 2 || N == 3) return true;
	if ((N & 1) == 0 || N % 3 == 0 || N == 1) return false;

	for (int i = 5; i * i <= N; i += 6)
	{
		if (N % i == 0 || N % (i + 2) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, m, n;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> m >> n;
		for (int j = m; j <= n; j++)
		{
			if (is_prime(j))
			{
				cout << j << "\n";
			}
		}
		cout << "\n";
	}
	return 0;
}
