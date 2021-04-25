#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int clr[300000];
pii idx[300000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, C, M, A, B;
	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> clr[i], idx[i] = {clr[i], i};

	sort(idx, idx + N);
	srand(time(0));

	cin >> M;
	while (M--) {
		cin >> A >> B; --A, --B; int diff = B - A + 1;
		for (int i = 0; i < 50; i++) {
			int num = clr[A + (rand() << 16 | rand()) % diff];
			if (2 * (upper_bound(idx, idx + N, make_pair(num, B)) - lower_bound(idx, idx + N, make_pair(num, A))) > diff) {
				cout << "yes " << num << '\n';
				goto nxt;
			}
		}
		cout << "no\n"; nxt:;
	}
	return 0;
}
