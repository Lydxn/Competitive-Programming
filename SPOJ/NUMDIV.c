// WIP

#include <math.h>
#include <stdio.h>

#define ifc(x) (sieve[(x) >> 6] & (1 << (((x) >> 1) & 31)))
#define isc(x) (sieve[(x) >> 6] |= (1 << (((x) >> 1) & 31)))

int sieve[15625], prime[78498], pidx;
int bases[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

long long mulmod(long long a, long long b, long long m) {
    return (__uint128_t) a * b % m;
}

long long powmod(long long a, long long e, long long m) {
	if (e == 1) return a % m;
	if (e & 1) return mulmod(a, powmod(a, e - 1, m), m);
	long long k = powmod(a, e >> 1, m);
	return mulmod(k, k, m);
}

int is_prime(long long n) {
    if (n == 1) return 0;
	long long d = n - 1;
	int s = 0;
	while (!(d & 1)) ++s, d >>= 1;

	for (int i = 0; i < 9; ++i) {
		int a = bases[i];
		if (a >= n) break;
		if (powmod(a, d, n) != 1) {
			int pass = 0;
			for (int r = 0; r < s; ++r)
				if (powmod(a, d << r, n) == n - 1)
					pass = 1;
			if (!pass) return 0;
		}
	}
	return 1;
}

int main() {
	for (int i = 3; i * i < 1000001; i += 2)
		if (!ifc(i))
			for (int j = i * i, k = i << 1; j < 1000001; j += k)
				isc(j);

	prime[pidx++] = 2;
	for (int i = 3; i < 1000001; i += 2)
		if (!ifc(i))
			prime[pidx++] = i;

	int T; long long N;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &N);

		int ans = 1;
		for (int i = 0; ; i++) {
			int p = prime[i];
			if ((long long) p * p * p > N) break;

			int cnt = 1;
			while (N % p == 0) N /= p, ++cnt;
			ans *= cnt;
		}

		long long sq = sqrt(N);
		if (is_prime(N)) ans <<= 1;
		else if (sq * sq == N && is_prime(sq)) ans *= 3;
		else if (N != 1) ans <<= 2;

		printf("%d\n", ans);
	}
	return 0;
}
