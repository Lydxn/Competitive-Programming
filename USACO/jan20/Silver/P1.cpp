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

priority_queue<int> pq, b;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);

	int N, K, B, mx = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> B, b.push(B);
	for (int i = 1; i <= b.top(); i++) {
		pq = b; int cur = 0;
		for (int j = 0; j < K; j++) {
			if (pq.empty()) goto bad;
			int x = pq.top(); pq.pop();
			if (j >= K / 2) cur += min(i, x);
			if (x >= i) pq.push(x - i);
		}
		mx = max(mx, cur);
		bad:;
	}
	cout << mx << '\n';
	return 0;
}
