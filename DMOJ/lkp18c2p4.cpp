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

RollingHash<200000, int, 1000000007, 'a', 0> hsh;
vector<int> valid;
int pre[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string S; ll cnt = 0;
	cin >> N >> S;

	hsh.init(S.begin(), S.end());
	for (int i = 0; i < N; i++) {
		if ((pre[i] = hsh.get_hash(0, i)) == hsh.get_hash(N - i - 1, N - 1)) {
			valid.push_back(i);
		}
	}

	for (int i = 0; i < N; i++) {
		int l = 0, r = N - i, m;
		while (l <= r) {
			m = (l + r) >> 1;
			if (hsh.get_hash(i, i + m) == pre[m]) l = m + 1;
			else r = m - 1;
		}
		cnt += upper_bound(valid.begin(), valid.end(), r) - valid.begin();
	}

	cout << cnt << '\n';
	return 0;
}
