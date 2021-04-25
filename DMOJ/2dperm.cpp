#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int diff[25000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, Q, q;
	cin >> N >> M >> Q;

	int NM = N * M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			++diff[i * j], --diff[NM - (N - i + 1) * (M - j + 1) + 2];
	for (int i = 1; i <= NM; i++) diff[i] += diff[i - 1];

	while (Q--) {
		cin >> q;
		cout << diff[q] << '\n';
	}
	return 0;
}
