int setbits(unsigned long long N)
{
    return __builtin_popcountll(N);
}
