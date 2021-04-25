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

unordered_map<ll, bool> pa, pb;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	ll N, M, K, a, b;
	cin >> N >> M >> K;
	while (K--) {
		cin >> a >> b;
		pa[a] ^= 1, pb[b] ^= 1;
	}

	vector<ll> va, vb;
	for (auto i : pa)
		if (i.second) va.push_back(i.first);
	for (auto i : pb)
		if (i.second) vb.push_back(i.first);

	int mx = max(va.size(), vb.size());
	cout << mx << '\n';
	for (int i = 0; i < mx; i++) {
		if (i < int(va.size()) && i < int(vb.size())) cout << va[i] << ' ' << vb[i] << '\n';
		else if (i < int(va.size())) cout << va[i] << ' ' << 1 << '\n';
		else cout << 1 << ' ' << vb[i] << '\n';
	}
	return 0;
}