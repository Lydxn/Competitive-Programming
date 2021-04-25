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

int x[1000], y[1000], w[1000], l[1000];
unordered_set<ll> ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, N, X, Y;
	cin >> R >> N;
	for (int i = 0; i < R; i++) cin >> x[i] >> y[i] >> w[i] >> l[i];
	while (N--) {
		cin >> X >> Y;
		for (int i = 0; i < R; i++)
			if (x[i] <= X && X < x[i] + w[i] && y[i] <= Y && Y < y[i] + l[i])
				ans.insert(i);
	}
	cout << ans.size() << '\n';
	return 0;
}
