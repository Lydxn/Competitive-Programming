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

vector<int> m[3];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0, x; i < N; i++) cin >> x, m[x % 3].push_back(x);

	int c0 = m[0].size(), c1 = m[1].size(), c2 = m[2].size();
	if (c0 > c1 + c2 + 1 || (c0 == 0 && c1 > 0 && c2 > 0)) {
		cout << "impossible\n";
		return 0;
	}

	deque<int> ans;
	for (int i = 0, k = 0; i < c0 - 1; i++) {
		if (c1 == 0) k = 1;
		ans.push_back(0), ans.push_back(k + 1), --(k ? c2 : c1);
	}

	if (c0) ans.push_back(0);
	for (int i = 0; i < c1; i++) ans.push_front(1);
	for (int i = 0; i < c2; i++) ans.push_back(2);

	for (int i : ans) cout << m[i].back() << ' ', m[i].pop_back();
	cout << '\n';
	return 0;
}
