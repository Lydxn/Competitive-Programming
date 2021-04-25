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

	string S, tmp = ""; vector<string> ss;
	cin >> S; int sz = S.size();
	for (int i = 0; i < sz - 1; i++) tmp += string(i + 1, S[i]);
	tmp += string(sz, S[sz - 1]);
	for (int i = sz - 2; i >= 0; i--) tmp += string(i + 1, S[i]);

	sz = tmp.size();
	for (int i = 0; i <= sz / 2; i++) {
		ss.push_back(tmp);
		tmp[i + 1] = tmp[0], tmp[sz - i - 2] = tmp[sz - 1];
	}

	sz = ss.size();
	for (int i = 0; i < sz - 1; i++) cout << ss[i] << '\n';
	cout << ss[sz - 1] << '\n';
	for (int i = sz - 2; i >= 0; i--) cout << ss[i] << '\n';
	return 0;
}
