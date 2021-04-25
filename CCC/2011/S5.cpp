#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;
bool vis[1 << 25];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, light, init = 0;
	cin >> K;
	for (int i = 0; i < K; i++) cin >> light, init = init << 1 | light;

	vis[init] = false; q.emplace(init, 0);
	while (!q.empty()) {
		int v = q.front().first, d = q.front().second; q.pop();
		if (v == 0) {
			cout << d << '\n';
			return 0;
		}

		for (int i = 0; i < K; i++) {
			if (!(v & (1 << i))) {
				int nv = v | (1 << i), csc = 0;
				for (int j = 0; j < K; j++) {
					if (nv & (1 << j)) ++csc;
					else {
						if (csc >= 4) for (int k = j - csc; k < j; k++) nv ^= 1 << k;
						csc = 0;
					}
				}
				if (csc >= 4) for (int j = K - csc; j < K; j++) nv ^= 1 << j;

				if (!vis[nv]) {
					vis[nv] = true;
					q.emplace(nv, d + 1);
				}
			}
		}
	}
}
