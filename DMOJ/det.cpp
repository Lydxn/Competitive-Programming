#include <iostream>

typedef long long ll;

using namespace std;

const int MOD = 1000000007;
ll matrix[500][500];

ll pow_mod(ll a, int b)
{
	ll res = 1;
	a %= MOD;

	while (b > 0)
	{
		if (b & 1)
		{
			res = (res * a) % MOD;
		}

		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

int determinant(int N)
{
	ll res = 1;
	for (int i = 0; i < N; i++)
	{
		int pivot = i;
		for (int j = i + 1; j < N; j++) {
			if (matrix[j][i] > matrix[pivot][i])
			{
				pivot = j;
			}
		}

		if (pivot != i)
		{
			swap(matrix[pivot], matrix[i]);
			res = -res;
		}

		for (int j = i + 1; j < N; j++)
		{
			ll sub = matrix[j][i] * pow_mod(matrix[i][i], MOD - 2) % MOD;
			for (int k = i + 1; k < N; k++)
			{
				matrix[j][k] = (matrix[j][k] - sub * matrix[i][k]) % MOD;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		res = (res * matrix[i][i] % MOD + MOD) % MOD;
	}
	return res;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
	
	cout << determinant(N) << "\n";
	return 0;
}
