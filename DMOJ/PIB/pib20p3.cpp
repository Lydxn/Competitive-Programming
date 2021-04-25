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

BITRangePoint<100000, int, 1> bit;
vector<int> two;
int idx = 0;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q, op, x, prev = -1;
	cin >> Q;

	bit.init();
	while (Q--) {
		cin >> op;
		if (op == 1) ++idx, bit.update(idx, idx, 1), prev = 1;
		else if (op == 2) {
			++idx;
			if (prev != 2) two.push_back(idx);
			bit.update(two.back() - 1, idx, 1);
			prev = 2;
		} else {
			cin >> x;
			cout << bit.query(x) % 2 << '\n';
		}
	}
	return 0;
}

/*
8
1
3 1
2
2
2
3 4
2
3 4

1
1
1
0
*/
