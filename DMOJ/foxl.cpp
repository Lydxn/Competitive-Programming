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
int par[200001], midx, ans;

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
void join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return;
	par[v] = u, ++ans;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, A, B;
	cin >> N >> M;
	while (M--) {
		cin >> A >> B;
		if (!mp.count(A)) mp[A] = midx++, par[mp[A]] = mp[A];
		if (!mp.count(B)) mp[B] = midx++, par[mp[B]] = mp[B];
		join(mp[A], mp[B]);
	}
	cout << N - ans << '\n';
	return 0;
}