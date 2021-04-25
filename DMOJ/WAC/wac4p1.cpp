#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[201];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, op, l, r;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> a[i];

	while (Q--) {
		cin >> op >> l >> r;
		if (op == 1) sort(a + l, a + r + 1);
		else sort(a + l, a + r + 1, greater<int>());
	}

	for (int i = 1; i <= N; i++) cout << a[i] << (i == N ? "" : " ");
	cout << '\n';
	return 0;
}
