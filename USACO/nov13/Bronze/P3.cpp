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

vector<string> d[100], adj[30];
vector<string> ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("nocow.in", "r", stdin);
	freopen("nocow.out", "w", stdout);

	int N, K; string _;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> _ >> _ >> _ >> _;
		for (int j = 0; cin >> _; j++) {
			if (_ == "cow.") break;
			d[i].push_back(_), adj[j].push_back(_);
		}
	}

	int sz = d[0].size();
	for (int i = 0; i < sz; i++) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
	}

	int r = 0, c = 0;
	while (K && c < sz) {
		int cnt = 1;
		for (int j = c + 1; j < sz; j++) cnt *= adj[j].size();
		for (int j = 0; j < N; j++) {
			bool good = d[j][c] == adj[c][r];
			for (int k = 0; k < c; k++) good &= d[j][k] == ans[k];
			cnt -= good;
		}

		if (K > cnt) K -= cnt, ++r;
		else ans.push_back(adj[c][r]), ++c, r = 0;
	}

	string f;
	for (auto i : ans) f += " " + i;
	cout << f.substr(1) << '\n';
	return 0;
}
