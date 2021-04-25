#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 100001, BLKSZ = 316;
pair<int, int> A[MAX];
int rnk[MAX], N;
ll ans[MAX], BIT[MAX], cur;

struct qu {
	int l, r, i;
	qu() {}
	qu(int l, int r, int i) : l(l), r(r), i(i) {}
	bool operator< (const qu& q) { return l / BLKSZ == q.l / BLKSZ ? (l / BLKSZ & 1 ? r < q.r : r > q.r) : l < q.l; }
} q[MAX];

void update(int i, int v) {
	for (; i <= N; i += i & -i) BIT[i] += v;
}

ll query(int i) {
	ll res = 0;
	for (; i > 0; i -= i & -i) res += BIT[i];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Q, l, r;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> A[i].first, A[i].second = i;
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++) rnk[A[i].second] = i;

	cin >> Q;
	for (int i = 0; i < Q; i++) cin >> l >> r, q[i] = qu(l, r, i);
	sort(q, q + Q);

	for (int i = 0, cl = 1, cr = 0; i < Q; i++) {
		while (cl < q[i].l) {
			cur -= query(rnk[cl] - 1);
			update(rnk[cl++], -1);
		}
		while (cl > q[i].l) {
			cur += query(rnk[--cl] - 1);
			update(rnk[cl], 1);
		}
		while (cr < q[i].r) {
			cur += ++cr - cl - query(rnk[cr]);
			update(rnk[cr], 1);
		}
		while (cr > q[i].r) {
			cur -= cr - cl + 1 - query(rnk[cr]);
			update(rnk[cr--], -1);
		}
		ans[q[i].i] = cur;
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
	return 0;
}
