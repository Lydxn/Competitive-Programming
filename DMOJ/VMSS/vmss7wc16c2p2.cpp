#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int psa[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string G; int Q, l, r;
	cin >> G >> Q;
	for (int i = 0; i < int(G.size()); i++) psa[i + 1] = psa[i] + (G[i] == 'G');

	while (Q--) {
		cin >> l >> r;
		cout << psa[r + 1] - psa[l] << '\n';
	}
	return 0;
}
