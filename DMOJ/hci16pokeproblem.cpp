#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool adj[101][101];
int type[100];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, C, A, B, T, maxx = 0, ans = 0;
	cin >> N >> C;
	for (int i = 0; i < C; i++) {
		cin >> A >> B;
		adj[A][B] = true;
	}

	cin >> T;
	for (int i = 0; i < T; i++) cin >> type[i];

	for (int i = 1; i <= N; i++) {
		int eff = 0;
		for (int j = 0; j < T; j++) eff += adj[i][type[j]] - adj[type[j]][i];
		if (eff > maxx) maxx = eff, ans = i;
	}

	cout << ans << '\n';
	return 0;
}
