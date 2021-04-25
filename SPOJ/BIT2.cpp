#include <iostream>

typedef long long ll;

using namespace std;

const int MAXBITS = 30;
ll power[MAXBITS + 1];

void init_pow()
{
	power[0] = 1;
	for (int i = 1; i <= MAXBITS; i++) power[i] = power[i - 1] << 1;
}

int main()
{
	init_pow();
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	ll N, res, extra;
	while (T--) 
	{
		cin >> N;

		int bits = 0;
		res = 0;

		for (int i = MAXBITS; i >= 0; i--) 
		{
			extra = power[i] * bits + (i * power[i] >> 1);
			if (N > extra) 
			{
				N -= extra;
				res += power[i];
				++bits;
			}
		}

		if (N == bits) printf("%lld\n", res);
		else printf("Does Not Exist.\n");
	}
	return 0;
}
