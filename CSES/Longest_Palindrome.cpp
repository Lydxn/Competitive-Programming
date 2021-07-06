#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

ll hsh[1000001], rhsh[1000002], pw[1000001];

ll ch(int l, int r) { return (hsh[r] - hsh[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD; }
ll crh(int l, int r) { return (rhsh[l] - rhsh[r + 1] * pw[r - l + 1] % MOD + MOD) % MOD; }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size(), mx = 0, ans = -1;
	pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 31 % MOD;
	for (int i = 1; i <= n; i++) hsh[i] = (hsh[i - 1] * 31 + s[i - 1]) % MOD;
	for (int i = n; i; i--) rhsh[i] = (rhsh[i + 1] * 31 + s[i - 1]) % MOD;

	for (int i = 1; i <= n; i++) {
		int l = 1, r = min(i, n - i + 1);
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (ch(i - mid + 1, i) == crh(i, i + mid - 1)) l = mid + 1;
			else r = mid - 1;
		}
		if (r * 2 - 1 > mx) mx = r * 2 - 1, ans = i - r;

		l = 1, r = min(i, n - i);
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (ch(i - mid + 1, i) == crh(i + 1, i + mid)) l = mid + 1;
			else r = mid - 1;
		}
		if (r * 2 > mx) mx = r * 2, ans = i - r;
	}
	cout << s.substr(ans, mx) << '\n';
	return 0;
}
