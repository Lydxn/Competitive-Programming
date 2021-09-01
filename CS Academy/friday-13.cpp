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

int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string wd[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	int idx = find(wd, wd + 7, S) - wd, ans = 0;
	for (int i = 0; i < 12; i++) {
		ans += (idx + 12) % 7 == 5;
		idx = (idx + m[i]) % 7;
	}
	cout << ans << '\n';
	return 0;
}
