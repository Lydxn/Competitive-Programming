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

int w[1001], bark[1001], cnt[1001];
vector<int> adj[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int D, F, T, a, b;
	cin >> D;
	for (int i = 1; i <= D; i++) cin >> w[i];
	cin >> F;
	while (F--) cin >> a >> b, adj[a].push_back(b);

	cin >> T;
	memset(bark, -1, sizeof(bark)); bark[1] = 0;
	for (int i = 0; i <= T; i++) {
		for (int j = 1; j <= D; j++) {
			if (bark[j] == i) {
				++cnt[j];
				for (int k : adj[j])
					if (bark[k] < i) bark[k] = i + w[k];
			}
		}
	}

	for (int i = 1; i <= D; i++) cout << cnt[i] << '\n';
	return 0;
}
