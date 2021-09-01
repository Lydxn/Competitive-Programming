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

const int BASE = 31;
int pw[25001], hsh[25001], rhsh[25002];

int shsh(int idx, int len) {
	return (hsh[idx + len - 1] - 1LL * hsh[idx - 1] * pw[len] % MOD + MOD) % MOD;
}

int rshsh(int idx, int len) {
	return (rhsh[idx] - 1LL * rhsh[idx + len] * pw[len] % MOD + MOD) % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string S;
	cin >> N >> S;
	pw[0] = 1;
	for (int i = 1; i <= N; i++) pw[i] = pw[i - 1] * 31LL % MOD;
	for (int i = 1; i <= N; i++) hsh[i] = (hsh[i - 1] * 31LL + S[i - 1]) % MOD;
	for (int i = N; i; i--) rhsh[i] = (rhsh[i + 1] * 31LL + S[i - 1]) % MOD;
	int len = 0, idx = -1;
	for (int i = 1, l, r; i <= N; i++) {
		l = 1, r = min(i, N - i);
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (shsh(i - mid + 1, mid) == rshsh(i + 1, mid)) l = mid + 1;
			else r = mid - 1;
		}
		if (r * 2 > len) len = r * 2, idx = i - r + 1;
		l = 1, r = min(i - 1, N - i);
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (shsh(i - mid, mid) == rshsh(i + 1, mid)) l = mid + 1;
			else r = mid - 1;
		}
		if (r * 2 + 1 > len) len = r * 2 + 1, idx = i - r;
	}
	cout << S.substr(idx - 1, len) << '\n' << len << '\n';
	return 0;
}
