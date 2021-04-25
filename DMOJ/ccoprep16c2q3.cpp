#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, K[200000], blk[200000], hops[200000], nxt[200000];

void update(int x, int v) {
	K[x] = v;
	for (int i = x; i >= 0 && blk[i] == blk[x]; i--) {
		if (i + K[i] < N && blk[i] == blk[i + K[i]]) hops[i] = hops[i + K[i]] + 1, nxt[i] = nxt[i + K[i]];
		else hops[i] = 1, nxt[i] = i + K[i];
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q, op, x, v;
	cin >> N;
	for (int i = 0, blksz = sqrt(N); i < N; i++) cin >> K[i], blk[i] = i / blksz;
	for (int i = N - 1; i >= 0; i--) update(i, K[i]);
	cin >> Q;

	while (Q--) {
		cin >> op >> x;
		if (op == 1) {
			int ans = 0;
			while (x < N) ans += hops[x], x = nxt[x];
			cout << ans << '\n';
		} else {
			cin >> v;
			update(x, v);
		}
	}
	return 0;
}
