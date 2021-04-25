#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
	int l, r, k, i;
	qu() {}
	bool operator< (const qu& q) { return k < q.k; }
};

ll psa[200001], ans[200000];
pair<int, int> arr[200000];
qu q[200000];
BIT<200000, ll, 1> bit;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;

	for (int i = 0; i < N; i++) cin >> arr[i].first, arr[i].second = i + 1, psa[i + 1] = psa[i] + arr[i].first;
	sort(arr, arr + N);
	bit.init();

	for (int i = 0; i < Q; i++) cin >> q[i].l >> q[i].r >> q[i].k, q[i].i = i;
	sort(q, q + Q);

	for (int i = 0, idx = 0; i < Q; i++) {
		while (idx < N && arr[idx].first < q[i].k) bit.update(arr[idx].second, arr[idx].first), ++idx;
		ans[q[i].i] = psa[q[i].r] - psa[q[i].l - 1] - 2 * bit.query(q[i].l, q[i].r);
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
	return 0;
}
