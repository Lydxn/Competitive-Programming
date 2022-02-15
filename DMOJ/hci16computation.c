// TLE

#include <stdio.h>

#define MOD 1000000007

int main() {
    int N; long long x;
    scanf("%d", &N);
    for (int i = 0; i < 16; i++) {
        scanf("%lld", &x), x %= MOD;
        long long s = x;
        for (int n = 1; n < N; n++) {
            long long X = x * x % MOD;
            long long Y = X * (31 - __builtin_clz(X)) % MOD;
            s += x = Y * (Y + x) % MOD * (Y + x) % MOD;
        }
        printf("%lld%c", s, " \n"[i == 15]);
    }
    return 0;
}