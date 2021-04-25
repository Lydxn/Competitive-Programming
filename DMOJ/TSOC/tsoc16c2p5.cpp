#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime[10000], visited[10000];
int prices[99];

vector<int> init_sieve(int n)
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;

	vector<int> primes;
	for (int i = 2; i <= n; i++)
	{
		if (is_prime[i])
		{
			primes.push_back(i - 2);
			for (int j = i * i; j <= n; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	return primes;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, spent;
	cin >> n >> m;
	vector<int> primes = init_sieve(n);

	for (int i = 0; i < m; i++) cin >> prices[i];

	int min_price = 0;
	for (int p : prices) min_price += 2 * p;

	visited[min_price] = true;
	for (int i = min_price; i <= n; i++)
	{
		if (visited[i])
		{
			if (is_prime[i])
			{
				cout << "its primetime\n";
				return 0;
			}
			else
			{
				for (int j : prices)
				{
					for (int k : primes)
					{
						spent = k * j + i;
						if (spent <= n) visited[spent] = true;
						else break;
					}
				}
			}
		}
	}

	cout << "not primetime\n";
	return 0;
}
