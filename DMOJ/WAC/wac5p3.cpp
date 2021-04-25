#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int b[200000], cnt[200001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> b[i];

	for (int i = 1; i * i <= N; i++) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0, d = 0; j < N; j++) {
			int t0 = b[j], t1 = b[j - i * i];
			++cnt[t0];
			if (cnt[t0] == i) ++d;
			else if (cnt[t0] - 1 == i) --d;

			if (j >= i * i) {
				--cnt[t1];
				if (cnt[t1] == i) ++d;
				else if (cnt[t1] + 1 == i) --d;
			}

			if (d == i) ++ans;
		}
	}

	cout << ans << '\n';
	return 0;
}
