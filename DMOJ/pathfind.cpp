#include <bits/stdc++.h>

// when in doubt, turn everything into long long
#define idk(r, c) { \
	if ((r) == 1) val |= 1; \
	if ((r) == N) val |= 2; \
	if ((c) == 1) val |= 4; \
	if ((c) == M) val |= 8; \
}

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_set<ll> uset;
queue<pair<ll, ll>> q;
pair<ll, ll> dir[8] = {{0, 1}, {0, -1}, {1, 1}, {1, 0}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N, M, K, r, c;
	cin >> N >> M >> K;

	while (K--) cin >> r >> c, uset.insert(r << 20LL | c);

	while (!uset.empty()) {
		ll val = 0;
		ll s = *uset.begin(); uset.erase(s);
		idk(s >> 20, s & 1048575);

		q = {}; q.emplace(s >> 20, s & 1048575);
		while (!q.empty()) {
			ll cr = q.front().first, cc = q.front().second; q.pop();
			for (auto d : dir) {
				ll nr = cr + d.first, nc = cc + d.second;
				if (uset.count(nr << 20LL | nc)) {
					uset.erase(nr << 20LL | nc);
					q.emplace(nr, nc);
					idk(nr, nc);
				}
			}
		}

		if (val != 6 && val != 9 && val != 0 && val != 1 && val != 2 && val != 4 && val != 8) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}
