#include <bitset>

const int MAXN = 1000001;
bitset<MAXN> primes;
bool initialized;

void init()
{
    initialized = true;
    primes.set(1);
    for (long long i = 2; i < MAXN; i++)
    {
        if (!primes[i])
        {
            for (long long j = i * i; j < MAXN; j += i)
            {
                primes.set(j);
            }
        }
    }
}

bool f(int N)
{
    if (!initialized) init();
    return !primes[N];
}
