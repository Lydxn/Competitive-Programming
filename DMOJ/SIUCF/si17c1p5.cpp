#include <iostream>

typedef long long ull;

using namespace std;

pair<ull, ull> p01 = make_pair(0, 1);
const int MOD = 1000000000;
ull a, b, c, d;

pair<ull, ull> fib(ull N)
{
	if (N <= 0) return p01;
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
    cin.sync_with_stdio(0);
    cin.tie(0);

    ull a, b, n;
    cin >> a >> b >> n;

    cout << ((n == 0 ? a : n == 1 ? b : fib(n - 1).first * a % MOD + fib(n).first * b % MOD) % MOD) << '\n';
    return 0;
}
