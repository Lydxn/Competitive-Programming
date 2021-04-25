#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct beb { int B, D, C, i; } b[50000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int S, N;
	cin >> S >> N;
	for (int i = 0; i < N; i++) cin >> b[i].B >> b[i].D >> b[i].C, b[i].i = i;

	sort(b, b + N, [&] (beb x, beb y) {
		if (x.B != y.B) return x.B > y.B;
		if (x.B >= S) return x.C > y.C || (x.C == y.C || x.i < y.i);
		return x.D > y.D || (x.D == y.D || x.i < y.i);
	});

	int Q, x;
	cin >> Q;
	while (Q--) {
		cin >> x;
		cout << b[x - 1].i + 1 << '\n';
	}
	return 0;
}
