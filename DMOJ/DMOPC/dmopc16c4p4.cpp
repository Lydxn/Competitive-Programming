#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int BLKSZ = 316;
struct qu {
	int l, r, i;
	bool operator< (const qu& q) { return l / BLKSZ == q.l / BLKSZ ? (l / BLKSZ & 1 ? r < q.r : r > q.r) : l < q.l; }
};

int a[100001], ans[100000], freq[100001];
qu queries[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, p, q, cur = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	cin >> Q;
	for (int i = 0; i < Q; i++) cin >> p >> q, queries[i] = {p, q, i};
	sort(queries, queries + N);

	for (int i = 0, cl = 0, cr = 0; i < Q; i++) {
		while (cl < queries[i].l) --freq[a[cl]], cur += freq[a[cl]] > 0 ? freq[a[cl]] & 1 ? -1 : 1 : 0, ++cl;
		while (cl > queries[i].l) ++freq[a[--cl]], cur += freq[a[cl]] > 1 ? freq[a[cl]] & 1 ? -1 : 1 : 0;
		while (cr < queries[i].r) ++freq[a[++cr]], cur += freq[a[cr]] > 1 ? freq[a[cr]] & 1 ? -1 : 1 : 0;
		while (cr > queries[i].r) --freq[a[cr]], cur += freq[a[cr]] > 0 ? freq[a[cr]] & 1 ? -1 : 1 : 0, --cr;
		ans[queries[i].i] = cur;
	}

	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
	return 0;
}
