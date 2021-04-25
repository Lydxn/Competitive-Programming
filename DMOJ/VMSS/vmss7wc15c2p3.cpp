#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

ll H[400000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N; ll ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];

	stack<pair<ll, int>> st;
	for (int i = 0; i < N; i++) {
		int occ = 1;
		while (!st.empty() && H[st.top().first] <= H[i]) {
			if (H[st.top().first] == H[i]) occ += st.top().second;
			ans += st.top().second, st.pop();
		}
		if (!st.empty()) ++ans;
		st.emplace(i, occ);
	}
	cout << ans << '\n';
	return 0;
}
