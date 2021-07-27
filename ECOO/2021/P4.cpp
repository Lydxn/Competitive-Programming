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

	ll K, s = 0;
	cin >> K; ++K;
	vector<ll> f;
	for (ll i = 2; i * i <= K; i++)
		while (K % i == 0)
			K /= i, f.push_back(i), s += i;
	if (K > 1) f.push_back(K), s += K;
	if (s - int(f.size()) > 100000) { cout << "Sad Chris\n"; return 0; }
	vector<int> ans;
	for (int i = 0; i < int(f.size()); i++)
		while (--f[i]) ans.push_back(i + 1);
	int sz = ans.size();
	cout << sz << '\n';
	for (int i = 0; i < sz; i++)
		cout << ans[i] << " \n"[i == sz - 1];
	return 0;
}