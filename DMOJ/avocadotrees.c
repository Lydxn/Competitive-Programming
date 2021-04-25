#include <stdio.h>

#define max(a, b) (a > b ? a : b)

int psa[1000001];

int main() {
	int N, Q, H, a, b, ans = 0;
	scanf("%d%d%d", &N, &Q, &H);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &a, &b);
		psa[i] = psa[i - 1] + b * (a <= H);
	}
	while (Q--) {
		scanf("%d%d", &a, &b);
		ans = max(ans, psa[b] - psa[a - 1]);
	}
	printf("%lld\n", ans);
}