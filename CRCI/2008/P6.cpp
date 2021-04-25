#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template <const int MAXN, typename T, const int INDEXING>
struct BITRangePoint {
	T bit[MAXN + 1]; int N;
	void init(int N = MAXN) { this->N = N; std::fill(bit, bit + N + 1, 0); }
	template <typename It> void init(It st, It en) {
		N = en - st; std::fill(bit, bit + N + 1, 0);
		for (int i = 1; i <= N; i++) update(i, i, *(st + i - 1));
	}
	void update(int l, int r, T x) { update_(l, x); update_(r + 1, -x); }
	T query(int i) { T sum = 0; for (i += 1 - INDEXING; i; i -= i & -i) sum += bit[i]; return sum; }
private:
	void update_(int i, T x) { for (i += 1 - INDEXING; i <= N; i += i & -i) bit[i] += x; }
};

BITRangePoint<100000, int, 1> cnt;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, L, R;
	cin >> N;

	cnt.init();
	while (N--) {
		cin >> L >> R;
		int ql = cnt.query(L), qr = cnt.query(R);
		cout << ql + qr << '\n';
		cnt.update(L, L, -ql); cnt.update(R, R, -qr);
		cnt.update(L + 1, R - 1, 1);
 	}
	return 0;
}
