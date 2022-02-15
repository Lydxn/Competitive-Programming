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

map<string, int> mp;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	vector<int> p; int m = 1; bool b = false;
	for (int i = S.size() - 1; i >= 0; ) {
		if (isdigit(S[i])) {
			vector<int> dig;
			while (isdigit(S[i])) dig.push_back(S[i--] - '0');
			int x = 0;
			for (int j = dig.size() - 1; j >= 0; j--)
				x = x * 10 + dig[j];
			b = i >= 0 && S[i] != ')';
			p.push_back(x), m *= x;
		} else if (isalpha(S[i])) {
			string s = string(1, S[i]);
			while ('a' <= S[i] && S[i] <= 'z') s = S[--i] + s;
			mp[s] += m, --i;
			if (b) m /= p.back(), p.pop_back(), b = false;
		} else if (S[i] == '(') {
			m /= p.back(), p.pop_back();
			--i;
		} else --i;
	}
	for (auto [k, v] : mp) {
		if (v == 1) cout << k;
		else cout << k << v;
	}
	cout << '\n';
	return 0;
}
