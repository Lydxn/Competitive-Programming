#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <const int MAXN, typename T>
struct BIT {
    T bit[MAXN + 1];
    int _N;

    void init(const int N = MAXN) {
        _N = N;
        memset(bit, 0, sizeof(bit));
    }

    void init(const auto& a, const int N = MAXN) {
        _N = N;
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= _N; i++) {
            bit[i] += a[i];
            int idx = i + (i & -i);
            if (idx <= N) bit[idx] += bit[i];
        }
    }

    void update(int i, const T x) {
        for (; i <= _N; i += i & -i) bit[i] += x;
    }

    T query(int i) {
        T res = 0;
        for (; i > 0; i -= i & -i) res += bit[i];
        return res;
    }

    T query(const int l, const int r) {
        return query(r) - query(l - 1);
    }
};

const int MAXN = 150001;
int psa[MAXN];
BIT<MAXN + MAXN, int> bit;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

	int N, v, sum = 0; ll cnt = 0;
	cin >> N;

    bit.init(); bit.update(MAXN, 1);
    for (int i = 1; i <= N; i++) {
        cin >> v;
        sum += v == 1 ? 1 : -1, cnt += bit.query(sum + MAXN - 1);
        bit.update(sum + MAXN, 1);
	}

	cout << cnt << '\n';
    return 0;
}
