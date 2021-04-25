#include <iostream>

using namespace std;

const int MAXN = 1000001, MOD = 1000000007;
int totient[MAXN];
bool f[MAXN];

void init_totient(int N)
{
	for (int i = 1; i <= N; i++)
	{
		totient[i] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		if (totient[i] == i)
		{
			for (int j = i; j <= N; j += i)
			{
				totient[j] -= totient[j] / i;
			}
		}
	}
}

void init_f(int N)
{
	f[1] = true;
	for (int i = 2; i * i <= N; i++)
	{
		for (int j = i * i; j <= N; j *= i)
		{
			f[j] = true;
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	init_totient(N);
	init_f(N);

	long long res = 0;
	for (int i = 0; i <= N; i++)
	{
		res = (res + f[totient[i]] * totient[i]) % MOD;
	}
	
	cout << res << "\n";
	return 0;
}
