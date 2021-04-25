#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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

RollingHash<2000, int, 1000000007, 'A', 1> hsh;
int dp[2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S;
	for (int _ = 0; _ < 10; _++) {
		cin >> S;
		hsh.init(S.begin(), S.end());

		memset(dp, 0, sizeof(dp)); int len = S.size();
		for (int i = 0; i <= len; i++) {
			for (int j = i - 1; j >= 0; j -= 2) {
				int mid = (i + j) / 2;
				if (hsh.get_hash(j, mid) == hsh.get_hash(mid + 1, i)) {
					dp[i] = max(dp[i], dp[j - 1] + i - j + 1);
				}
			}
		}
		cout << *max_element(dp, dp + len + 1) << '\n';
	}
	return 0;
}
