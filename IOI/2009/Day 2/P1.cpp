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

int R[101], W[2001], C[2001];
set<int> s;
queue<int> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, d, ans = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> R[i];
	for (int i = 1; i <= M; i++) cin >> W[i];

	for (int i = 1; i <= N; i++) s.insert(i);
	for (int i = 0; i < 2 * M; i++) {
		if (!q.empty() && !s.empty()) d = q.front(), q.pop();
		else cin >> d;
		if (d > 0) {
			if (s.empty()) q.push(d), --i;
			else {
				int b = *s.begin();
				s.erase(b), C[d] = b, ans += R[b] * W[d];
			}
		} else s.insert(C[-d]);
	}
	cout << ans << '\n';
	return 0;
}

