#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;

template <const int MAXN, typename T, const T MOD, const int OFFSET, const int INDEXING>
struct RollingHash {
	T pre[MAXN + 1], hsh[MAXN + 1]; const int WORD_SIZE = sizeof(T);
	T add_mod(T a, T b) { T res = a + b; if (res >= MOD) res -= MOD; return res; }
	T sub_mod(T a, T b) { T res = a - b; if (res < 0) res += MOD; return res; }
	T mul_mod(T a, T b) { return WORD_SIZE <= 4 ? uint64_t(a) * b % MOD : __int128_t(a) * b % MOD; }
	template <typename It> void init(It st, It en, const T BASE = 13131LL) {
		int N = en - st; pre[0] = 1, hsh[N] = 0;
		for (int i = 1; i <= N; i++) pre[i] = mul_mod(pre[i - 1], BASE);
		for (int i = N - 1; i >= 0; i--) hsh[i] = add_mod(mul_mod(hsh[i + 1], BASE), *(st + i) - OFFSET + 1);
	}
	T get_hash(int l, int r) { l -= INDEXING, r -= INDEXING - 1; return sub_mod(hsh[l], mul_mod(hsh[r], pre[r - l])); }
	T concat(T a, T b, int alen) { return add_mod(a, mul_mod(b, pre[alen])); }
};

RollingHash<200000, ll, 1000000000000007, 'a', 0> hsh;
gp_hash_table<ll, null_type> uset;
string S; int L;

bool f(int len) {
	uset.clear();
	for (int i = 0; i < L - len + 1; i++) {
	    ll h = hsh.get_hash(i, i + len - 1);
	    if (uset.find(h) != uset.end()) return true;
	    uset.insert(h);
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> S;
	hsh.init(S.begin(), S.end());

	int l = 0, r = L, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (f(mid)) l = mid + 1;
		else r = mid - 1;
	}

	cout << r << '\n';
	return 0;
}
