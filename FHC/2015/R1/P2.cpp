// apparently the only string algorithm i know is hashing

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize "Ofast"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

const int MAXN = 1000000; const ll MASK = (1LL << 40) - 1;
gp_hash_table<ll, null_type> uset;
ll p[MAXN];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, ans, len; string S;
	cin >> T;

	p[0] = 1; for (int i = 1; i < MAXN; i++) p[i] = (p[i - 1] * 98765432LL) & MASK;
	for (int i = 1; i <= T; i++) {
		cin >> N; uset.clear(); ans = 0;
		while (N--) {
			cin >> S; len = S.size(); ll h = 0;
			for (int i = 0; i < len; i++) {
				h = (h + S[i] * p[i]) & MASK;
				if (uset.find(h) == uset.end()) {
					ans += i + 1;
					goto nxt;
				}
			}

			ans += len; nxt:; h = 0;
			for (int i = 0; i < len; i++) uset.insert(h = (h + S[i] * p[i]) & MASK);
		}
		cout << "Case #" << i << ": " << ans << '\n';
	}
	return 0;
}
