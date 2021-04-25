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

pair<string, int> w[1000000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("auto.in", "r", stdin);
	freopen("auto.out", "w", stdout);

	int W, N, K; string S;
	cin >> W >> N;
	for (int i = 0; i < W; i++) cin >> w[i].first, w[i].second = i + 1;
	sort(w, w + W);
	while (N--) {
		cin >> K >> S;
		int ans = lower_bound(w, w + W, make_pair(S, -1)) - w + K - 1;
		cout << (w[ans].first.substr(0, S.size()) != S ? -1 : w[ans].second) << '\n';
	}
	return 0;
}
