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

set<string> ans;
unordered_set<string> dp;

void dfs(string S) {
	if (dp.count(S)) return;
	dp.insert(S);
	
	vector<int> l; vector<pii> lr;
	for (int i = 0; i < int(S.size()); i++) {
		if (S[i] == '(') l.push_back(i);
		if (S[i] == ')') lr.emplace_back(i, l.back()), l.pop_back();
	}

	for (auto i : lr) {
		string cur;
		for (int j = 0; j < int(S.size()); j++)
			if (j != i.first && j != i.second) cur += S[j];
		dfs(cur); ans.insert(cur);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	dfs(S);
	for (auto i : ans) cout << i << '\n';
	return 0;
}
