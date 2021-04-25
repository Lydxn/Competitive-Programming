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

struct query {
	int x, type, i;
	bool operator< (const query &q) {
		return x < q.x || (x == q.x && type < q.type);
	}
} qu[300000];
int qidx, ans[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b;
	cin >> N >> Q;
	while (N--) {
		cin >> a >> b;
		qu[qidx++] = {a, 0, -1}, qu[qidx++] = {b, 2, -1};
	}
	
	for (int i = 0; i < Q; i++) {
		cin >> a;
		qu[qidx++] = {a, 1, i};
	}
	
	sort(qu, qu + qidx);
	for (int i = 0, v = 0; i < qidx; i++) {
		if (qu[i].type == 0) ++v;
		else if (qu[i].type == 2) --v;
		else ans[qu[i].i] = v;
	}
	
	for (int i = 0; i < Q; i++)
		cout << ans[i] << '\n';
	return 0;
}
