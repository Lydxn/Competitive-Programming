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

	string s;
	cin >> s;

	bool flag = true;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (char c : s) {
		if ('a' <= c && c <= 'z') ++cnt1;
		else if ('A' <= c && c <= 'Z') ++cnt2;
		else if ('0' <= c && c <= '9') ++cnt3;
		else flag = false;
	}

	int len = s.size();
	cout << (8 <= len && len <= 12 && flag && cnt1 >= 3 && cnt2 >= 2 && cnt3 >= 1 ? "Valid" : "Invalid") << '\n';
	return 0;
}
