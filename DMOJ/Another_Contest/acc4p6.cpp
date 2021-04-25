bool f(int N)
{
    while (N != 1)
    {
        if (N == 4 || N == 16 || N == 37 || N == 58 || N == 89 || N == 145 || N == 42 || N == 20) return false;
        int temp = N;
        int sum = 0, rem = 0;
        
        while (temp > 0) {
            rem = temp % 10;
            sum += rem * rem;
            temp /= 10;
        }
        N = sum;
    }
    return true;
}
