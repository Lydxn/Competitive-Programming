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

int N, h[100000];
multiset<int> hs, ds;
vector<int> ans;

void solve(int x, int y) {
	hs.clear(), ds.clear(), ans = {h[x], h[y]};
	int diff = h[y] - h[x];
	for (int i = 0; i < N; i++)
		if (i != x && i != y) hs.insert(h[i]);

	int p = -1;
	for (int i : hs) {
		if (p != -1) ds.insert(i - p);
		p = i;
	}

	for (int i = h[y] + diff; ; i += diff) {
		if (*ds.begin() == *ds.rbegin()) {
			cout << ans.size() << '\n';
			for (int j : ans) cout << j << ' ';
			cout << '\n' << N - ans.size() << '\n';
			for (int j : hs) cout << j << ' ';
			cout << '\n';
			exit(0);
		}

		auto it = hs.find(i), nxt = next(it), prv = prev(it);
		if (it == hs.end()) break;
		if (it != hs.begin()) ds.erase(ds.find(*it - *prv));
		if (nxt != hs.end()) ds.erase(ds.find(*nxt - *it));
		if (it != hs.begin() && nxt != hs.end()) ds.insert(*nxt - *prv);
		hs.erase(it), ans.push_back(i);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> h[i];
	sort(h, h + N);

	if (N == 2) { cout << "1\n" << h[0] << "\n1\n" << h[1] << '\n'; return 0; }
	if (N == 3) { cout << "1\n" << h[0] << "\n2\n" << h[1] << ' ' << h[2] << '\n'; return 0; }
	

	solve(0, 1), solve(0, 2), solve(1, 2);
	cout << "-1\n";
	return 0;
}
