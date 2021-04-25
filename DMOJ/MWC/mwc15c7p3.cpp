#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

queue<int> q;
int dist[1 << 20];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, S, L, R, I, msk = 0; char c;
	cin >> N >> M >> S >> L >> R >> I;
	for (int i = 0; i < N; i++) cin >> c, msk = msk << 1 | (c == 'B');

	memset(dist, 0x3f, sizeof(dist));
	dist[msk] = 0; q.push(msk);
	while (!q.empty()) {
		int cv = q.front(); q.pop();

		// query 1
		if (dist[cv] + S <= M) {
			for (int i = 0; i < N; i++) {
				int nv = cv ^ (1 << i);
				if (dist[cv] + S < dist[nv]) dist[nv] = dist[cv] + S, q.push(nv);
			}
		}

		// query 2
		if (dist[cv] + L <= M) {
			int nv = ((cv << 1) & ((1 << N) - 1)) | ((cv >> (N - 1)) & 1);
			if (dist[cv] + L < dist[nv]) dist[nv] = dist[cv] + L, q.push(nv);
		}

		// query 3
		if (dist[cv] + R <= M) {
			int nv = (cv >> 1) | ((cv & 1) << (N - 1));
			if (dist[cv] + R < dist[nv]) dist[nv] = dist[cv] + R, q.push(nv);
		}

		// query 4
		if (dist[cv] + I <= M) {
			int nv = cv ^ ((1 << N) - 1);
			if (dist[cv] + I < dist[nv]) dist[nv] = dist[cv] + I, q.push(nv);
		}
	}

	int cnt = 0;
	for (int i = 0; i < (1 << N); i++)
		if (dist[i] <= M) ++cnt;
	cout << cnt << '\n';
	return 0;
}
