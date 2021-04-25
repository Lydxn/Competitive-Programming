#include <bits/stdc++.h>

using namespace std;

int R[30001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b, c;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> R[i];

	while (Q--) {
		cin >> a >> b >> c; int m1 = INT_MAX, m2 = INT_MAX;
		for (int i = a; i <= b; i++) m1 = min(m1, R[i] = max(R[i] - c, 0));
		for (int i = 1; i <= N; i++) m2 = min(m2, R[i]);
		cout << m1 << ' ' << m2 << '\n';
	}
	return 0;
}
