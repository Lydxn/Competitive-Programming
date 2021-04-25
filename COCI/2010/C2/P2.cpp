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

	int N; string S;
	cin >> N;
	vector<string> ans;
	while (N--) {
		cin >> S; S += "?";
		string cur; bool flag = false;
		for (char c : S) {
			if ('0' <= c && c <= '9') cur += c, flag = true;
			else if (flag) {
				while (cur[0] == '0' && cur.size() > 1) cur = cur.substr(1);
				ans.push_back(cur), cur = "", flag = false;
			}
		}
	}

	sort(ans.begin(), ans.end(), [&] (string a, string b) {
		return a.size() < b.size() || (a.size() == b.size() && a.compare(b) < 0);
	});
	for (auto i : ans) cout << i << '\n';
	return 0;
}
