#include <bits/stdc++.h>

using namespace std;

template <const int MAXN, typename T, const T MOD, const int OFFSET>
struct Hashing {
    inline T add_mod(const T a, const T b) { T res = a + b; return res < MOD ? res : res - MOD; }
    inline T sub_mod(const T a, const T b) { T res = a - b; return res >= 0 ? res : res + MOD; }
    inline T mul_mod(const T a, const T b) { return a * b % MOD; }

	T pre[MAXN + 1], hsh[MAXN + 1];
	const T SEED = 131; // change this value if needed (must be smaller than MOD)

	void init(const auto& s, const int N = MAXN) {
		pre[0] = 1, hsh[N] = 1;
		for (int i = 1; i <= N; i++) pre[i] = mul_mod(pre[i - 1], SEED);
		for (int i = N - 1; i >= 0; i--) hsh[i] = add_mod(mul_mod(hsh[i + 1], SEED), s[i] - OFFSET + 1);
	}

	T get_hash(int l, int r) {
		return sub_mod(hsh[l], mul_mod(hsh[r], pre[r - l]));
	}
};

const int MAXN = 305, MOD = 1000000007;
Hashing<MAXN, long long, MOD, '0'> pre[MAXN], suf[MAXN];
int R, C;

bool valid(int sz) {
    for (int i = 0; i <= R - sz; i++) {
        for (int j = 0; j <= C - sz; j++) {
            for (int k = 0; k < sz; k++) {
                if (pre[i + k].get_hash(j, j + sz) != suf[sz + i - k - 1].get_hash(C - sz - j, C - j)) goto nxt;
            }
            return true; nxt:;
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string row;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> row;
        pre[i].init(row, C);
        reverse(row.begin(), row.end());
        suf[i].init(row, C);
    }

    for (int i = min(R, C); i > 1; i--) {
        if (valid(i)) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}
