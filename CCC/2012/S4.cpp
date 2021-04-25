#include <bits/stdc++.h>
#define _top(i) (cur >> ((i) << 3) & 255 ? __builtin_ctz(cur >> ((i) << 3) & 255) : -1)
#define _move(i, j) cur ^ ((1ULL << ((i) << 3 | top)) | (1ULL << ((j) << 3 | top)));

using namespace std;

typedef unsigned long long ll;

queue<ll> q;
unordered_map<ll, int> dist;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n, coin; ll init = 0, end = 0;
		cin >> n;
		if (n == 0) return 0;

		for (int i = 0; i < n; i++) {
			cin >> coin;
			init |= 1ULL << (i << 3 | coin), end |= 1ULL << (i << 3 | (i + 1));
		}

		q = {}; dist.clear();
		q.push(init); dist[init] = 0;

		while (!q.empty()) {
			ll cur = q.front(); q.pop();
			if (cur == end) {
				cout << dist[cur] << '\n';
				goto nxt;
			}

			for (int i = 0; i < n; i++) {
				ll top = _top(i);
				if (top == -1) continue;

				if (i != 0 && top < _top(i - 1)) {
					ll ncur = _move(i, i - 1);
					if (!dist.count(ncur)) {
						dist[ncur] = dist[cur] + 1;
						q.push(ncur);
					}
				}

				if (i != n - 1 && top < _top(i + 1)) {
					ll ncur = _move(i, i + 1);
					if (!dist.count(ncur)) {
						dist[ncur] = dist[cur] + 1;
						q.push(ncur);
					}
				}
			}
		}
		cout << "IMPOSSIBLE\n"; nxt:;
	}
}
