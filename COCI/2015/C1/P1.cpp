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

int cnt[4];
unordered_map<char, int> mp = {{'P', 0}, {'K', 1}, {'H', 2}, {'T', 3}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S; unordered_set<int> ss;
	cin >> S;
	for (int i = 0; i < int(S.size()); i += 3) {
		cnt[mp[S[i]]]++;
		ss.insert(mp[S[i]] << 16 | S[i + 1] << 8 | S[i + 2]);
	}

	if (int(ss.size()) * 3 != int(S.size())) cout << "GRESKA\n";
	else cout << 13 - cnt[0] << ' ' << 13 - cnt[1] << ' ' << 13 - cnt[2] << ' ' << 13 - cnt[3] << '\n';
	return 0;
}
