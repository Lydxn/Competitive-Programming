#include <stdio.h>
#include <stdlib.h>

int _, __[7];
#define scanu(x) for (x = getchar() & 15; (_ = getchar()) & 16; x = (x << 3) + (x << 1) + (_ & 15))
void putnumu(int x) { _ = 0; do __[_++] = x % 10; while(x /= 10); while(_--) putchar(__[_] | 48); putchar('\n'); }

unsigned long long *p[24];
int len[24];

int get(int i) {
	int b = 32 - __builtin_clz(i);
	int l = b * (i - (1 << (b - 1))), r = l + b, bl = l >> 6, br = r >> 6;
	int res = (p[b][bl] >> (l & 63)) & ((1 << b) - 1);
	if (bl != br) res |= (p[b][br] << (64 - (l & 63))) & ((1 << b) - 1);
	return res;
}

void set(unsigned long long x, int i) {
	int b = 32 - __builtin_clz(i);
	int l = b * len[b]++, r = l + b, bl = l >> 6, br = r >> 6;
	p[b][bl] |= x << (l & 63);
	if (bl != br) p[b][br] |= x >> (64 - (l & 63));
}

int main() {
	for (int i = 1; i < 23; i++)
		p[i] = calloc(((1 << (i - 1)) * i + 7) >> 3, 1);
	p[23] = calloc(5191376, 1);

	int N, Q, x, y;
	scanu(N); scanu(Q);
	for (int i = 2, x; i <= N; i++) {
		scanu(x);
		set(x, i);
	}

	while (Q--) {
		scanu(x); scanu(y);
		while (x != y) {
			if (x < y) y = get(y);
			else x = get(x);
		}
		putnumu(x);
	}

	for (int i = 0; i < 24; i++)
		free(p[i]);
	return 0;
}
