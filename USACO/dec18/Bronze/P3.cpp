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

unordered_set<int> cnt;
multiset<int> B[2];

void f(int d, int sum) {
	if (d == 4) { cnt.insert(sum); return; }
	auto &x = B[d % 2], &y = B[(d + 1) % 2], tmp = x;
	for (int i : tmp) {
		x.erase(x.find(i)), y.insert(i);
		f(d + 1, d % 2 ? sum + i : sum - i);
		x.insert(i), y.erase(y.find(i));
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);

	int x;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10; j++)
			cin >> x, B[i].insert(x);

	f(0, 1000);
	cout << cnt.size() << '\n';
	return 0;
}
