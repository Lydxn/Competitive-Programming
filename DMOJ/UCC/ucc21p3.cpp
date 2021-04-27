#include <bits/stdc++.h>

using namespace std;

long long d[10000002];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, R, x, y;
	cin >> N >> x >> y >> R;
	for (int i = 0; i < R; i++) {
		int a, b;
		cin >> a >> b;
		++d[a], --d[b + 1];
	}
	for (int i = 1; i <= N; i++) d[i] += d[i - 1];
	for (int i = 1; i <= N; i++) d[i] += d[i - 1];
	cout << d[y] - d[x - 1] << '\n';
	return 0;
}