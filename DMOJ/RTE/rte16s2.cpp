#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_set<int> dp[2501];
string L, mp[4];
pii dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int r, int c, int idx) {
	if (dp[idx].count(r << 13 | c)) return;
	dp[idx].insert(r << 13 | c);

	for (int i = 0; i < 4; i++) {
		if (L.substr(idx, mp[i].size()) == mp[i]) {
			dfs(r + dir[i].first, c + dir[i].second, idx + mp[i].size());
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) cin >> mp[i];
	cin >> L;

	dfs(2500, 2500, 0);
	cout << dp[L.size()].size() << '\n';
	return 0;
}
