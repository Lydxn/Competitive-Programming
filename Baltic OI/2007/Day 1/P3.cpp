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

deque<int> mn, mx;
int a[1000000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, c; bool none = true;
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (!mn.empty() && mn.front() <= i - m) mn.pop_front();
		if (!mx.empty() && mx.front() <= i - m) mx.pop_front();
		while (!mn.empty() && a[mn.back()] > a[i]) mn.pop_back();
		while (!mx.empty() && a[mx.back()] < a[i]) mx.pop_back();
		mn.push_back(i), mx.push_back(i);
		if (i >= m - 1 && a[mx.front()] - a[mn.front()] <= c)
			cout << i - m + 2 << '\n', none = false;
	}
	
	if (none) cout << "NONE\n";
	return 0;
}
