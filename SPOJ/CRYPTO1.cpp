#include <ctime>
#include <iostream>

typedef unsigned int ui;
typedef unsigned long long ull;

using namespace std;

const ui MOD = 4000000007;

ui mod_pow(ull a, ui b, ull m)
{
	ull res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % m;
		}

		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

ui decrypt(ui timestamp)
{
	ui mp = mod_pow(timestamp, 1000000002, MOD);
	return mp > MOD / 2 ? MOD - mp : mp;
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	ui timestamp;
	cin >> timestamp;

	time_t ts = decrypt(timestamp);
	cout << asctime(gmtime(&ts)) << "\n";
	return 0;
}
