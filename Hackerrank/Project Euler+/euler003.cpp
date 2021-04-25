#include <iostream>

using namespace std;

long long max_prime_factor(long long N)
{
	long long max_div;
	while (N % 2 == 0)
	{
		max_div = 2;
		N >>= 1;
	}


	for (long long i = 3; i * i <= N; i += 2)
	{
		while (N % i == 0)
		{
			max_div = i;
			N /= i;
		}
	}
	return N > 2 ? N : max_div;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	long long N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << max_prime_factor(N) << '\n';
	}
	return 0;
}
