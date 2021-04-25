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

ll powmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD, b >>= 1;
	}
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string s;
	cin >> N;
	stack<string> stk;
	while (cin >> s) stk.push(s);

	stack<int> mstk; ll m = 1;
	while (!stk.empty()) {
		string x = stk.top(); stk.pop();
		if (x == "(") m = m * powmod(mstk.top(), MOD - 2) % MOD, mstk.pop();
		else {
			string y = stk.top(); stk.pop();
			int v = stoi(x);
			if (y == ")") m = m * v % MOD, mstk.push(v);
			else mp[y] = (mp[y] + m * v) % MOD;
		}
	}

	for (auto i : mp) cout << i.first << ' ' << i.second << '\n';
	return 0;
}