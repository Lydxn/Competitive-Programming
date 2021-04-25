#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	long long N, sum, a, b, c;
	while (T--)
	{
		cin >> N;

		sum = 10, a = 2, b = 8, c;
		while (true)
		{
			c = 4 * b + a;
			if (c >= N) break;

			sum += c;
			a = b, b = c;
		}
		cout << sum << '\n';
	}
	return 0;
}
