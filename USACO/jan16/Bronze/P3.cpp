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

int T[2001][2001];
unordered_map<char, pii> mp = {{'N', {0, 1}}, {'E', {1, 0}}, {'S', {0, -1}}, {'W', {-1, 0}}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

	int N, S, x = 1000, y = 1000, t = 0, ans = INF; char D;
	cin >> N;
	memset(T, -1, sizeof(T));
	while (N--) {
		cin >> D >> S;
		while (S--) {
			x += mp[D].first, y += mp[D].second, ++t;
			if (T[x][y] != -1) ans = min(ans, t - T[x][y]);
			T[x][y] = t;
		}
	}
	cout << (ans == INF ? -1 : ans) << '\n';
	return 0;
}
