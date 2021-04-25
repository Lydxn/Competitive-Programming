unsigned long long duplicatebits(unsigned long long N)
{
    N = (N | (N << 16)) & 0x0000FFFF0000FFFF;
    N = (N | (N << 8)) & 0x00FF00FF00FF00FF;
    N = (N | (N << 4)) & 0x0F0F0F0F0F0F0F0F;
    N = (N | (N << 2)) & 0x3333333333333333;
    N = (N | (N << 1)) & 0x5555555555555555;
    return N | (N << 1);
}
