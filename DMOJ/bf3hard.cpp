#include <iostream>

typedef long long ll;

using namespace std;

ll mulmod(ll A, ll B, ll M)
{
	ll X = 0;
	ll Y = A % M;

	while (B > 0)
	{
		if (B & 1)
		{
			X = (X + Y) % M;
		}

		Y = (Y << 1) % M;
		B >>= 1;
	}
	return X;
}

ll powmod(ll A, ll B, ll M)
{
	ll X = 1;
	ll Y = A;

	while (B > 0)
	{
		if (B & 1)
		{
			X = mulmod(X, Y, M);
		}

		Y = mulmod(Y, Y, M);
		B >>= 1;
	}
	return X;
}

bool miller_rabin(ll N, int K)
{
	if (N < 2 || (N != 2 && (N & 1) == 0)) return false;
	
	ll D = N - 1;
	while ((D & 1) == 0)
	{
		D >>= 1;
	}

	for (int i = 0; i < K; i++)
	{
		ll A = rand() % (N - 1) + 1;
		ll temp = D;
		ll mod = powmod(A, temp, N);

		while (temp != N - 1 && mod != 1 && mod != N - 1)
		{
			mod = mulmod(mod, mod, N);
			temp <<= 1;
		}

		if (mod != N - 1 && (temp & 1) == 0)
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

	ll N;
	cin >> N;

	for (; ; N++)
	{
		if (miller_rabin(N, 1)) // for some reason it ACTUALLY passes with 1 iteration.
		{
			cout << N << "\n";
			return 0;
		}
	}
}
