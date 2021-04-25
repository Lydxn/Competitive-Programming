#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int p[6000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, y;
	cin >> N >> Q;
	for (int i = 2; i <= N; i++) cin >> p[i];

	while (Q--) {
		cin >> x >> y;
		while (x != y) {
			if (x < y) y = p[y];
			else x = p[x];
		}
		cout << x << '\n';
	}
	return 0;
}
