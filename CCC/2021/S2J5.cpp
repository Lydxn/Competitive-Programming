#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool r[5000001], c[5000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, x; char op;
	cin >> M >> N >> K;
	while (K--) {
		cin >> op >> x;
		if (op == 'R') r[x] ^= 1;
		else c[x] ^= 1;
	}

	int cntr = 0, cntc = 0;
	for (int i = 1; i <= M; i++) cntr += r[i];
	for (int i = 1; i <= N; i++) cntc += c[i];

	int ans = 0;
	ans += cntc * (M - cntr) + (N - cntc) * cntr;
	cout << ans << '\n';
	return 0;
}