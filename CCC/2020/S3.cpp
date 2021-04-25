#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

RollingHash<200000, ll, 10000000000007LL, 'a', 0> hsh;
int freq_n[26], freq_h[26];
unordered_set<ll> ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string N, H;
	cin >> N >> H;

	int n_sz = N.size(), h_sz = H.size();
	if (n_sz > h_sz) {
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < n_sz; i++) ++freq_n[N[i] - 'a'];
	for (int i = 0; i < n_sz; i++) ++freq_h[H[i] - 'a'];

	hsh.init(H.begin(), H.end());
	for (int i = 0; i <= h_sz - n_sz; i++) {
		for (int j = 0; j < 26; j++) if (freq_n[j] != freq_h[j]) goto nxt;
		ans.insert(hsh.get_hash(i, i + n_sz - 1)); nxt:;
		if (i != h_sz - n_sz) ++freq_h[H[i + n_sz] - 'a'], --freq_h[H[i] - 'a'];
	}

	cout << ans.size() << '\n';
	return 0;
}
