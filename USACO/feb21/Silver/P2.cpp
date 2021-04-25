#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N, K, y[65537], g[65537];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> K; --K;
	for (int i = 1; i <= N; i++) cin >> y[i], y[i] /= 12;
	sort(y, y + N + 1);

	for (int i = 0; i < N; i++)
		g[i] = y[i + 1] - y[i] + (i == 0);
	sort(g, g + N, greater<int>());

	int ans = y[N] + 1;
	for (int i = 0; i < K; i++) ans -= max(0, g[i] - 1);
	cout << ans * 12 << '\n';
}