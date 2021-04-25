#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	int blue = __builtin_popcount((N ^ M) & ((1 << K) - 1));
	cout << blue << ' ' << K - blue << '\n';
	return 0;
}
