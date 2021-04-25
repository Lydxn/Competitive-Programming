#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool bad[301][301];
ll m[300], p[300];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b; ll ans = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> m[i] >> p[i];
		bad[i][i] = true;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b; --a, --b;
		bad[a][b] = bad[b][a] = true;
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, p[i]);
		for (int j = 0; j < N; j++) {
			if (bad[i][j]) continue;
			ans = max(ans, p[i] * m[j] + p[j]);
			for (int k = 0; k < N; k++) {
				if (bad[i][k] || bad[j][k]) continue;
				ans = max(ans, p[i] * m[j] * m[k] + p[j] * m[k] + p[k]);
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
