#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

const int BLK = 450;
struct query {
	int l, r, i;
	bool operator< (query &q) { return l / BLK < q.l / BLK || (l / BLK == q.l / BLK && r < q.r); }
} qu[200000];
int x[200001], ans[200000], cnt[200000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	map<int, int> mp; int midx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (!mp.count(x[i])) mp[x[i]] = midx++;
	}
	for (int i = 1; i <= n; i++) x[i] = mp[x[i]];
	
	for (int i = 0; i < q; i++) cin >> qu[i].l >> qu[i].r, qu[i].i = i;
	sort(qu, qu + q);
	
	for (int i = 0, cl = 1, cr = 0, cur = 0; i < q; i++) {
		while (cl < qu[i].l) {
			if (--cnt[x[cl]] == 0) --cur;
			++cl;
		}
		while (cl > qu[i].l) {
			if (++cnt[x[--cl]] == 1) ++cur;
		}
		while (cr < qu[i].r) {
			if (++cnt[x[++cr]] == 1) ++cur;
		}
		while (cr > qu[i].r) {
			if (--cnt[x[cr]] == 0) --cur;
			--cr;
		}
		ans[qu[i].i] = cur;
	}

	for (int i = 0; i < q; i++) cout << ans[i] << '\n';
	return 0;
}
