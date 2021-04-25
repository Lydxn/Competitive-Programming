#include <bits/stdc++.h>

using namespace std;

template <const int MAXN, typename T, const T MOD, const int OFFSET, const int INDEXING>
struct RollingHash {
	T pre[MAXN + 1], hsh[MAXN + 1]; const int WORD_SIZE = sizeof(T);
	T add_mod(T a, T b) { T res = a + b; if (res >= MOD) res -= MOD; return res; }
	T sub_mod(T a, T b) { T res = a - b; if (res < 0) res += MOD; return res; }
	T mul_mod(T a, T b) { return WORD_SIZE <= 4 ? uint64_t(a) * b % MOD : __int128_t(a) * b % MOD; }
	template <typename It> void init(It st, It en, const T BASE = MOD / 2 + 5) {
		int N = en - st; pre[0] = 1, hsh[N] = 0;
		for (int i = 1; i <= N; i++) pre[i] = mul_mod(pre[i - 1], BASE);
		for (int i = N - 1; i >= 0; i--) hsh[i] = add_mod(mul_mod(hsh[i + 1], BASE), *(st + i) - OFFSET + 1);
	}
	T get_hash(int l, int r) { l -= INDEXING, r -= INDEXING - 1; return sub_mod(hsh[l], mul_mod(hsh[r], pre[r - l])); }
	T concat(T a, T b, int alen) { return add_mod(a, mul_mod(b, pre[alen])); }
};

RollingHash<1000000, int, 1000000007, 'a', 0> hashing;
string s;

int solve(int l) {
	int r = int(s.size()) - l - 1;
	if (l == r) return 1;
	if (l > r) return 0;

	int res = 1;
	for (int i = l; i <= (l + r) / 2; i++) {
		if (hashing.get_hash(l, i) == hashing.get_hash(r - i + l, r)) {
			res = max(res, 2 + solve(i + 1));
			break;
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> s;
		hashing.init(s.begin(), s.end());
		cout << solve(0) << '\n';
	}
	return 0;
}
