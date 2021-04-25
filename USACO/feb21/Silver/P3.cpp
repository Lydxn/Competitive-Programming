#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int G[500][500], nxt1[500][501], nxt2[500][501];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N; ll ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> G[i][j];
		nxt1[i][N] = nxt2[i][N] = N;
		for (int j = N - 1; j >= 0; j--) {
			nxt1[i][j] = G[i][j] == 100 ? j : nxt1[i][j + 1];
			nxt2[i][j] = G[i][j] < 100 ? j : nxt2[i][j + 1];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int mn1 = N, mn2 = N;
			for (int k = i; k < N; k++) {
				mn1 = min(mn1, nxt1[k][j]), mn2 = min(mn2, nxt2[k][j]);
				if (mn1 < mn2) ans += mn2 - mn1;
			}
		}
	}
	cout << ans << '\n';
}