#include <bits/stdc++.h>

using namespace std;

vector<int> cycle;
vector<pair<int, int>> ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, cur = 1, e = 5000;
	cin >> K;

	do {
		while (e * (e - 1) / 2 > K) --e;
		cycle.push_back(e);
	} while (K -= e * (e - 1) / 2);

	for (int c : cycle) {
		for (int j = 0; j < c - 1; j++, cur++) ans.emplace_back(cur, cur + 1);
		ans.emplace_back(cur, cur - c + 1); ans.emplace_back(1, cur++);
	}

	cout << cur - 1 << ' ' << int(ans.size()) << '\n';
	for (const auto& a : ans) cout << a.first << ' ' << a.second << '\n';
	return 0;
}
