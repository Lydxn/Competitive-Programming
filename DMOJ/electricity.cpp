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

int x[100000];
bool p[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N; int ans = 0;
		vector<int> idxs;
		for (int i = 0; i < N; i++) {
			cin >> x[i] >> p[i];
			if (p[i]) idxs.push_back(i);
		}

		for (int i = 1; i < int(idxs.size()); i++) {
			int mx = 0;
			for (int j = idxs[i - 1] + 1; j <= idxs[i]; j++)
				mx = max(mx, x[j] - x[j - 1]);
			ans += mx;
		}
		cout << x[N - 1] - x[0] - ans << '\n';
	}
	return 0;
}
