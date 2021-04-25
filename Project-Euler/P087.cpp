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

const int MX = 50000000, SMX = sqrt(MX);
bool sv[SMX + 1];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	memset(sv, true, sizeof(sv)); sv[0] = sv[1] = false;
	for (int i = 2; i * i <= SMX; i++)
		if (sv[i])
			for (int j = i * i; j <= SMX; j += i)
				sv[j] = false;
	vector<int> p;
	for (int i = 2; i <= SMX; i++)
		if (sv[i]) p.push_back(i);

	set<int> ans;
	for (int a : p) {
		if (a * a > MX) break;
		for (int b : p) {
			if (b * b * b > MX) break;
			for (int c : p) {
				if (c * c * c * c > MX) break;
				int s = a * a + b * b * b + c * c * c * c;
				if (s <= MX) ans.insert(s);
			}
		}
	}
	cout << ans.size() << '\n';
	return 0;
}
