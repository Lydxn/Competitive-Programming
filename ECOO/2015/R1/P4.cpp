#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

string s, words[] = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};
int dp[400];

int solve(int idx) {
	if (idx >= int(s.size())) return 1;
	if (dp[idx] != -1) return dp[idx];

	int ans = 0;
	for (string w : words) {
		int sz = w.size();
		if (idx + sz <= int(s.size()) && s.substr(idx, sz) == w)
			ans += solve(idx + sz);
	}
	return dp[idx] = ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 10; _++) {
		cin >> s;
		memset(dp, -1, sizeof(dp));
		cout << solve(0) << '\n';
	}
	return 0;
}
