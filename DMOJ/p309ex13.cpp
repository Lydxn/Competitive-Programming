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

unsigned to10(string n, int b) {
	unsigned res = 0;
	for (char c : n) res = res * b + (c - '0');
	return res;
}

string from10(unsigned n, int b) {
	string res = "";
	while (n) {
		res += n % b + '0';
		n /= b;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, B1, B2, BF; string A, B; char op;
	cin >> T;
	while (T--) {
		cin >> B1 >> A >> B2 >> B >> op >> BF;
		unsigned NA = to10(A, B1), NB = to10(B, B2), ans;
		if (op == '+') ans = NA + NB;
		else if (op == '-') ans = NA - NB;
		else if (op == '*') ans = NA * NB;
		else ans = NA / NB;
		cout << from10(ans, BF) << '\n';
	}
	return 0;
}
