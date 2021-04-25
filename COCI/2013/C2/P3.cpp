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

unordered_set<string> ss;
int sz;

string f(string S) {
	string res = "";
	for (int i = 0; i < sz / 2; i++)
		res += S[i], res += S[sz - i - 1];
	if (sz & 1) res += S[sz / 2];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int X, cnt = 0; string S, T;
	cin >> X >> S; sz = S.size(), T = S;
	while (!ss.count(S)) ss.insert(S), S = f(S), ++cnt;
	
	X = cnt - X % cnt;
	while (X--) T = f(T);
	cout << T << '\n';
	return 0;
}
