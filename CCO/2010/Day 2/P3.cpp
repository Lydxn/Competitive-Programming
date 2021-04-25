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

int mp[27], cycle[27];
bool vis[27];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; string T; char c;
	for (int i = 0; i < 27; i++)
		cin >> c, mp[i] = c == '_' ? 26 :  c - 'A';
	for (int i = 0; i < 27; i++) {
		memset(vis, 0, sizeof(vis));
		for (int v = i; !vis[v]; v = mp[v])
			vis[v] = true, ++cycle[i];
	}
	
	cin >> N >> T;
	for (char c : T) {
		int v = c == '_' ? 26 : c - 'A';
		for (int i = 0; i < N % cycle[v]; i++)
			v = mp[v];
		cout << (char) (v == 26 ? '_' : v + 'A');
	}
	cout << '\n';
	return 0;
}
