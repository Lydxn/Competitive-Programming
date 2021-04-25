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

void solve() {
	unordered_set<string> uset;
	int N; string S;
	cin >> N;
	while (N--) {
		cin >> S;
		string DS = ""; int plus, at;
		at = S.find_first_of('@');
		for (int i = 0; i < int(S.size()); i++)
			if (!(S[i] == '.' && i < at)) DS += tolower(S[i]);

		plus = DS.find_first_of('+'), at = DS.find_first_of('@');
		if (plus != -1 && plus < at) DS.erase(DS.begin() + plus, DS.begin() + at);
		uset.insert(DS);
	}
	cout << uset.size() << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 10; _++) solve();
	return 0;
}
