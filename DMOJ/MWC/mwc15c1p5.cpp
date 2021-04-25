#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int f(string s) {
	ll ans = 0;
	for (int i = 0; i < int(s.size()); i++)
		ans += pow((s[i] & ~32) - 64 % 10, i % 4 + 1);
	ans %= 10;
	return ans == 0 ? 10 : ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string A, B;
	cin >> A >> B;

	cout << f(A) + f(B) << '\n';
	return 0;
}
