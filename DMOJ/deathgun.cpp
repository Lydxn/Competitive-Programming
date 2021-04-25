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

string mp[900]; int midx, in[900];
unordered_map<string, int> mp2;
vector<int> adj[900];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M; string a, b;
	cin >> M;
	while (M--) {
		cin >> a >> b;
		if (!mp2.count(a)) mp[mp2[a] = midx++] = a;
		if (!mp2.count(b)) mp[mp2[b] = midx++] = b;
		adj[mp2[b]].push_back(mp2[a]), ++in[mp2[a]];
	}

	while (true) {
		bool stop = true;
		for (int i = 0; i < midx; i++) {
			if (in[i] == 0) {
				cout << mp[i] << '\n', in[i] = -1, stop = false;
				for (auto j : adj[i]) --in[j];
				break;
			}
		}
		if (stop) break;
	}
	return 0;
}
