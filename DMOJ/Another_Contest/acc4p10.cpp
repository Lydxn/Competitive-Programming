#include <bitset>

using namespace std;

const int MAXN = 2000001;
bitset<MAXN> cache;
bool initialized;

void init()
{
	initialized = true;
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cache.set(i * i + j * j);
		}
	}
}

bool f(int n)
{
	if (!initialized) init();
	return cache[n];
}
