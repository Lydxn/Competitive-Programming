#include <stdio.h>
#include <string.h>

long long X[1000], Y[1000], arr[1000000], bucket[1000000];
int cnt[4096];

int main() {
	int N, x, y, aidx = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d%d", &x, &y), X[i] = x + 1000000, Y[i] = y + 1000000;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			long long x0 = X[i], y0 = Y[i], x1 = X[j], y1 = Y[j];
			arr[aidx++] = ((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1)) << 42LL | (x0 + x1) << 21LL | (y0 + y1);
		}
	}

	// unrolling ??
	for (int j = 0; j < aidx; j++) ++cnt[arr[j] & 4095];
	for (int j = 1; j < 4096; j++) cnt[j] += cnt[j - 1];
	for (int j = aidx - 1; j >= 0; j--) bucket[--cnt[arr[j] & 4095]] = arr[j];
	memcpy(arr, bucket, aidx << 3);

	memset(cnt, 0, 16384);
	for (int j = 0; j < aidx; j++) ++cnt[arr[j] >> 12 & 4095];
	for (int j = 1; j < 4096; j++) cnt[j] += cnt[j - 1];
	for (int j = aidx - 1; j >= 0; j--) bucket[--cnt[arr[j] >> 12 & 4095]] = arr[j];
	memcpy(arr, bucket, aidx << 3);

	int ans = 0, csc = 0;
	for (int i = 1; i < aidx; i++) {
		if (arr[i] == arr[i - 1]) ++csc;
		else ans += csc * (csc + 1) >> 1, csc = 0;
	}

	printf("%d\n", ans + (csc * (csc + 1) >> 1));
	return 0;
}
