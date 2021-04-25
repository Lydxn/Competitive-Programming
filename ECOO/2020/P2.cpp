#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_map<string, vector<pii>> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, M, P, Q, K, D; string S;
	cin >> T;

	while (T--) {
		mp.clear();
		cin >> N;
		while (N--) {
			cin >> M;
			while (M--) {
				cin >> S >> P >> Q;
				mp[S].emplace_back(P, Q);
			}
		}

		int ans = 0;
		cin >> K;
		while (K--) {
			cin >> S >> D;
			vector<pii> items = mp[S];
			sort(items.begin(), items.end());
			for (auto i : items) {
				if (D == 0) break;
				ans += min(D, i.second) * i.first;
				D -= min(D, i.second);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
