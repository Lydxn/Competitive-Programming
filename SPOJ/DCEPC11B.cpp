#include <iostream>

typedef long long ll;

using namespace std;

ll powmod(ll A, ll B, ll M)
{
	ll res = 1;
	while (B)
	{
		if (B & 1) res = res * A % M;
		B >>= 1;
		A = A * A % M;
	}
	return res;
}

ll factmod(int N, int P)
{
	if (N >= P) return 0;
	else
	{
		ll res = 1;
		for (int i = N + 1; i < P; i++)
		{
			res = res * i % P;
		}
		return (P - 1) * powmod(res, P - 2, P) % P;
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, P;
	cin >> T;

	while (T--)
	{
		cin >> N >> P;
		cout << factmod(N, P) << '\n';
	}
	return 0;
}
