#include <iostream>
#include <vector>

using namespace std;

const int MAX_PRIME = 104729;
bool is_prime[MAX_PRIME + 1];
vector<int> sieve;

void init_sieve()
{
	memset(is_prime, true, sizeof(is_prime));
	for (int i = 2; i * i <= MAX_PRIME; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= MAX_PRIME; j += i)
			{
				is_prime[j] = false;
			}
		}
	}

	for (int i = 2; i <= MAX_PRIME; i++)
	{
		if (is_prime[i]) sieve.push_back(i);
	}
}

int main()
{
	init_sieve();
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << sieve[N - 1] << '\n';
	}
	return 0;
}
