#include <stdio.h>
#include <string.h>

#define MOD 65535

int cnt[65536];
unsigned short q[MOD + 1], qans[MOD + 1];

int main() {
	int s, mx = 0, fidx = 0, bidx = -1;
	do {
		while (fidx > bidx || (q[bidx & MOD] != 0 && cnt[q[bidx & MOD]] <= 1))
			scanf("%d", &s), ++cnt[q[++bidx & MOD] = s];

		if (mx < bidx - fidx) {
			mx = bidx - fidx;
			int fm = fidx & MOD, bm = bidx & MOD;
			if (fm <= bm)
				memcpy(qans, q + fm, (bm - fm) << 1);
			else {
				memcpy(qans, q + fm, (MOD - fm + 1) << 1);
				memcpy(qans + (MOD - fm + 1), q, bm << 1);
			}
		}
		--cnt[q[fidx++ & MOD]];
	} while (fidx <= bidx);

	for (int i = 0; i < mx; i++)
		printf("%d\n", qans[i]);
	return 0;
}
