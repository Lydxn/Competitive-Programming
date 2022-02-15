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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> w(N), ans;
	for (int i = 0; i < N; i++) cin >> w[i];
	for (int i = 0; i < N - 1; i++) {
		int mx = 0;
		for (int j = 0; j < N - i; j++)
			if (w[mx] < w[j]) mx = j;
		ans.push_back(mx + 1);
		if (mx) ans.push_back(-mx);
		w.erase(w.begin() + mx);
	}
	ans.push_back(1); ans.push_back(-N);
	cout << ans.size() << '\n';
	for (int i : ans) cout << i << '\n';
	return 0;
}
