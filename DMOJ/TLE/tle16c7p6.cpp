#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int SEED = 131, MOD = 1000000007;
unordered_map<ll, vector<int>> p1, p2;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, l, r; string S;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> S;
		ll hsh = 0;
		for (int j = 0; j < int(S.size()); j++) hsh = (hsh * SEED + S[j]) % MOD, p1[hsh].push_back(i);
		p2[hsh].push_back(i);
	}

	while (M--) {
		cin >> S >> l >> r;
		int cnt = 0; ll hsh = 0;
		for (int j = 0; j < int(S.size()) - 1; j++)
			hsh = (hsh * SEED + S[j]) % MOD, cnt += upper_bound(p2[hsh].begin(), p2[hsh].end(), r) - lower_bound(p2[hsh].begin(), p2[hsh].end(), l);
		hsh = (hsh * SEED + S.back()) % MOD;
		cnt += upper_bound(p1[hsh].begin(), p1[hsh].end(), r) - lower_bound(p1[hsh].begin(), p1[hsh].end(), l);
		cout << cnt << '\n';
	}
	return 0;
}
