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

unordered_map<int, int> mp;

void solve() {
	int N;
	cin >> N;
	int ans = mp[N];
	cout << (char) (ans & 127) << (char) ((ans >> 7) & 127) << (char) ((ans >> 14) & 127) << (char) ((ans >> 21) & 127) << '\n';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 65; i <= 90; i++)
		for (int j = 65; j <= 90; j++)
			for (int k = 65; k <= 90; k++)
				for (int l = 65; l <= 90; l++)
					mp[(i * 1000000 + j * 10000 + k * 100 + l) % (i * 11 + j * 101 + k * 1009 + l * 10007)]
						= i | j << 7 | k << 14 | l << 21;

	for (int _ = 0; _ < 5; _++) solve();
	return 0;
}
