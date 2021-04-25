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

string S[25000];
pair<int, string> o[25001];
vector<int> ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, mx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		if (S[mx].size() < S[i].size()) mx = i;
	}
	for (int i = 0; i < N; i++) {
		int lcp = 0;
		while (lcp < int(S[mx].size()) && S[i][lcp] == S[mx][lcp]) ++lcp;
		o[i + 1] = {lcp, S[i]};
	}

	sort(o + 1, o + N + 1); o[0] = {-1, ""};
	for (int i = 1; i <= N; i++) {
		int lcp = 0;
		while (lcp < int(o[i - 1].second.size()) && o[i].second[lcp] == o[i - 1].second[lcp]) ++lcp;

		for (int j = 0; j < int(o[i - 1].second.size()) - lcp; j++) ans.push_back('-');
		for (int j = lcp; j < int(o[i].second.size()); j++) ans.push_back(o[i].second[j]);
		ans.push_back('P');
	}

	cout << ans.size() << '\n';
	for (char c : ans) cout << c << '\n';
	return 0;
}
