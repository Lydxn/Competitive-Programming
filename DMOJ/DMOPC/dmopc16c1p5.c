#include <stdio.h>

char _i[1 << 22], _; int _i0;
#define scanu(x) for (x = _i[_i0++] & 15; (_ = _i[_i0++]) & 16; x = (x << 3) + (x << 1) + (_ & 15))

int BIT[500001];

int main() {
    fread(_i, 1, 1 << 22, stdin);
    int N; long long cnt = 0;
    scanu(N);
    for (int i = 0, j, x, s; i < N; ++i) {
        scanu(x);
        for (s = 0, j = x; j; j -= j & -j) s += BIT[j];
        cnt += s < i - s ? s : i - s;
        for (; x <= N; x += x & -x) ++BIT[x];
    }

    printf("%lld\n", cnt);
    return 0;
}
