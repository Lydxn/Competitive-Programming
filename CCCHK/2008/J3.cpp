#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<int, pair<string, int>> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, D, num; string name;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> name >> num, mp[num] = {name, 0};

	cin >> D;
	while (D--) cin >> num, ++mp[num].second;

	int mx = INT_MIN, mn = INT_MAX; string ans;
	for (auto m : mp)
		if (mx < m.second.second) mx = m.second.second;
	for (auto m : mp)
		if (mx == m.second.second && mn > m.first) mn = m.first, ans = m.second.first;

	cout << ans << '\n';
	return 0;
}
