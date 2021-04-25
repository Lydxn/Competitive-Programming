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

const int BLKSZ = 447;
int A[200000], blk[200000 / BLKSZ + 1][200000];
vector<int> fact[200001];

void update(int i, int x) {
	for (int f : fact[A[i]]) blk[i / BLKSZ][f] += x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 200000; i++)
		for (int j = i; j <= 200000; j += i)
			fact[j].push_back(i);
			
	int N, Q, op, l, r, x, u, v;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> A[i], update(i, 1);
	while (Q--) {
		cin >> op;
		if (op == 1) {
			cin >> l >> r >> x; --l, --r;
			int cnt = 0, bl = l / BLKSZ, br = r / BLKSZ;
			if (bl == br)
				for (int i = l; i <= r; i++) cnt += A[i] % x == 0;
			else {
				for (int i = l; i < (bl + 1) * BLKSZ; i++) cnt += A[i] % x == 0;
				for (int i = bl + 1; i < br; i++) cnt += blk[i][x];
				for (int i = br * BLKSZ; i <= r; i++) cnt += A[i] % x == 0;
			}
			cout << cnt << '\n';
		} else {
			cin >> u >> v; --u;
			update(u, -1);
			A[u] = v, update(u, 1);
		}
	}
	return 0;
}
