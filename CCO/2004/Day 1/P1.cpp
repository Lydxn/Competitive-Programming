#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<char, pii> mp;
unordered_map<char, int> freq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int k, N, s, r; char a; string word;
	cin >> k;
	for (int i = 0; i < k; i++) cin >> a >> s >> r, mp[a] = {s, r};

	int ans = 0;
	cin >> N;
	while (N--) {
		cin >> word;
		freq.clear();
		for (char i : word) ++freq[i];

		int cur = 0;
		for (auto i : freq) {
			if (mp.count(i.first) && i.second <= mp[i.first].second) cur += mp[i.first].first * i.second;
			else goto toobad;
		}
		ans = max(ans, cur); toobad:;
	}
	cout << ans << '\n';
	return 0;
}
