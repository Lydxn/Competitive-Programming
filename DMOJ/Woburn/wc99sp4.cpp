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

vector<int> solve(int n) {
	if (n == 1) return {0};
	vector<int> ans;
	for (int i : solve(n >> 1)) ans.push_back(i << 1 | 1);
	for (int i : solve(n - (n >> 1))) ans.push_back(i << 1);
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m;
	while (m--) {
		cin >> n;
		for (int i : solve(n + 1)) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}
