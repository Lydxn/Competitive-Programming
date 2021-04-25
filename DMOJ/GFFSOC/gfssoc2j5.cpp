#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int psa[11][500001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b, num;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		for (int j = 1; j <= 10; j++) psa[j][i] = psa[j][i - 1];
		++psa[num][i];
	}

	while (Q--) {
		cin >> a >> b;
		for (int i = 10; i >= 1; i--) {
			int cnt = psa[i][a - 1] + psa[i][N] - psa[i][b];
			if (cnt > 0) {
				cout << i << ' ' << cnt << '\n';
				break;
			}
		}
	}
	return 0;
}
