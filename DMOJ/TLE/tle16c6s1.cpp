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

unordered_map<string, vector<int>> mp;
string t[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N; string s;
	cin >> T;
	for (int i = 0; i < T; i++) cin >> t[i];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> s, mp[s].push_back(i);
	for (int i = 0; i < T; i++)
		for (auto j : mp[t[i]]) cout << j << '\n';
	return 0;
}
