#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int h[10002], w[10001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll ans = 0;
	cin >> N;
	for (int i = 1; i <= N + 1; i++) cin >> h[i];
	for (int i = 1; i <= N; i++) cin >> w[i];
	for (int i = 1; i <= N; i++) ans += w[i] * (h[i] * 2 + h[i + 1] - h[i]);
	
	cout << ans / 2;
	if (ans % 2) cout << ".5";
	cout << '\n';
	return 0;
}