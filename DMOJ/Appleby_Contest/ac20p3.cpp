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

vector<int> idx[26];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ss, TT, p = -1, roll = 0; string s, T;
	cin >> ss >> TT >> s >> T;
	for (int i = 0; i < ss; i++) idx[s[i] - 'a'].push_back(i);
	for (char c : T) {
		if (idx[c - 'a'].empty()) { cout << "-1\n"; return 0; }
		auto it = lower_bound(idx[c - 'a'].begin(), idx[c - 'a'].end(), p + 1);
		if (it == idx[c - 'a'].end()) p = idx[c - 'a'][0], ++roll;
		else p = *it;
	}
	cout << 1LL * roll * ss + p + 1 << '\n';
	return 0;
}