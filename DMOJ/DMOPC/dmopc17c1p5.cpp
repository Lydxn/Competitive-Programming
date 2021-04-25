#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template <const int MAXN, typename T, const int INDEXING>
struct BIT {
	T bit[MAXN + 1]; int N;
	void init(int N = MAXN) { this->N = N; std::fill(bit, bit + N + 1, 0); }
	template <typename It> void init(It st, It en) {
		N = en - st; std::fill(bit, bit + N + 1, 0);
		for (int i = 1; i <= N; i++) {
			bit[i] += *(st + i - 1);
			int idx = i + (i & -i); if (idx <= N) bit[idx] += bit[i];
		}
	}
	void update(int i, T x) { for (i += 1 - INDEXING; i <= N; i += i & -i) bit[i] += x; }
	T query(int i) { T res = 0; for (i += 1 - INDEXING; i; i -= i & -i) res += bit[i]; return res; }
	T query(int l, int r) { return query(r) - query(l - 1); }
};

struct qu {
	int l, r, i;
	bool operator< (const qu& q) const { return l > q.l; }
};

BIT<1000000, int, 0> bit;
int arr[1000000], ans[1000000];
qu q[1000000];
stack<pii> mono;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, l, r;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < Q; i++) cin >> l >> r, q[i] = {l - 1, r - 1, i};

	sort(q, q + Q); bit.init();
	for (int i = N - 1, idx = 0; i >= 0; i--) {
		while (!mono.empty() && arr[i] > mono.top().first) bit.update(mono.top().second, -1), mono.pop();
		bit.update(i, 1); mono.emplace(arr[i], i);
		while (idx < Q && q[idx].l == i) ans[q[idx].i] = bit.query(q[idx].r), ++idx;
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
	return 0;
}
