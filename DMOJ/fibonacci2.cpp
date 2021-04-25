#include <iostream>

typedef unsigned long long ull;

using namespace std;

pair<ull, ull> p01 = make_pair(0, 1);
const int PISANO_PERIOD = 2000000016, MOD = 1000000007;
ull a, b, c, d;

pair<ull, ull> fib(int N)
{
	if (!N)
	{
		return p01;
	}
	else
	{
		pair<ull, ull> res = fib(N >> 1);
		a = res.first;
		b = res.second;
		c = a * ((b << 1) - a + MOD) % MOD;
		d = ((a * a) % MOD + (b * b) % MOD) % MOD;
		return (N & 1) == 0 ? make_pair(c, d) : make_pair(d, (c + d) % MOD);
	}
}

int main()
{
	ull N = 0;
	char ch;

	while (isdigit(ch = getchar_unlocked()))
	{
		N = (N * 10 + ch - '0') % PISANO_PERIOD;
	}

	printf("%ull", fib(N).first);
	return 0;
}
