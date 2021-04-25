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

bool bad[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);

	int N; string S;
	cin >> N >> S;
	unordered_map<string, int> mp;
	for (int i = 0; i < N; i++)
		for (int j = 1; j <= N - i; j++)
			mp[S.substr(i, j)]++;

	for (auto i : mp) bad[i.first.size()] |= i.second != 1;
	for (int i = 1; i <= N; i++)
		if (!bad[i]) { cout << i << '\n'; return 0; }
	return 0;
}
