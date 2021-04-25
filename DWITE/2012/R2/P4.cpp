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

void solve() {
	int N, a;
	vector<int> v, ans;
	cin >> N;
	for (int i = 1; i <= N; i++) v.push_back(i);
	for (int i = 0; i < N; i++) {
		cin >> a;
		int idx = N - i - a - 1;
		if (idx < 0) { cout << "IMPOSSIBLE\n"; return; }
		ans.push_back(v[idx]);
		v.erase(v.begin() + idx);
	}

	for (int i : ans) cout << i << ' ';
	cout << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) solve();
	return 0;
}
