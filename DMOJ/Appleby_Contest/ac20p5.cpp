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

int p[400001], sz[400001], s[400001], f[400001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, k = 0;
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> p[i];
	for (int i = 1; i <= N; i++) sz[i] = 1, s[i] = i;
	for (int i = 2; i * i <= N; i++)
		if (s[i] == i)
			for (int j = i * i; j <= N; j += i) s[j] = i;
			
	for (int i = N; i; i--) {
		sz[p[i]] += sz[i];
		for (int j = i; j != 1; j /= s[j]) ++f[s[j]];
		for (int j = sz[i]; j != 1; j /= s[j]) --f[s[j]];
	}
	
	for (int i = 2; i <= N; i++) k += f[i] > 0;
	cout << k << '\n';
	for (int i = 2; i <= N; i++)
		if (f[i] > 0) cout << i << ' ' << f[i] << '\n';
	return 0;
}
