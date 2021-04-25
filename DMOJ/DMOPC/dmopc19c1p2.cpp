#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sz[31];
string f0 = "Good writing is good writing is good writing.", f[3] = {"Good writing is good ", " writing is good ", " is good writing."};

char solve(int n, int k) {
	if (k >= sz[n]) return '.';
	if (n == 0) return f0[k];
	for (int i = 0; i < 3; i++) {
		if (k < int(f[i].size())) return f[i][k];
		k -= f[i].size();
		if (k < sz[n - 1]) return solve(n - 1, k);
		k -= sz[n - 1];
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	sz[0] = f0.size();
	for (int i = 1; i <= 30; i++) sz[i] = 2 * sz[i - 1] + f[0].size() + f[1].size() + f[2].size();

	int q, n, k;
	cin >> q;

	while (q--) {
		cin >> n >> k;
		cout << solve(n, k - 1) << '\n';
	}
	return 0;
}
