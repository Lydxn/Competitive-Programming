#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll dp[19][11][11][2];
string s;

ll actuallysolve(int pos, int p, int q, bool tight) {
	if (pos == int(s.size())) return 1;
	if (dp[pos][p][q][tight] != -1) return dp[pos][p][q][tight];

	ll res = 0;
	for (int i = 0; i <= (tight ? s[pos] - '0' : 9); i++) {
		if (i == p || i == q) continue;
		if (i == 0 && p == 10 && q == 10) res += actuallysolve(pos + 1, p, q, false);
		else res += actuallysolve(pos + 1, q, i, i == s[pos] - '0' ? tight : false);
	}
	return dp[pos][p][q][tight] = res;
}

ll solve(ll n) {
	s = to_string(n);
	memset(dp, -1, sizeof(dp));
	return actuallysolve(0, 10, 10, true);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;

	cout << solve(b) - solve(a - 1) << '\n';
	return 0;
}
