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

char grid[1001][1000];
int h[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int K, M, N;
	cin >> K;
	while (K--) {
		cin >> M >> N; int ans = 0;
		for (int i = 1; i <= M; i++)
			for (int j = 0; j < N; j++)
				cin >> grid[i][j];
		memset(h, 0, sizeof(h));
		for (int i = 1; i <= M; i++) {
			for (int j = 0; j < N; j++)
				h[j] = grid[i][j] == 'F' ? h[j] + 1 : 0;
			stack<int> st;
			for (int j = 0; j <= N; j++) {
				while (!st.empty() && h[j] <= h[st.top()]) {
					int H = h[st.top()]; st.pop();
					ans = max(ans, H * (st.empty() ? j : j - st.top() - 1));
				}
				st.push(j);
			}
		}
		cout << ans * 3 << '\n';
	}
	return 0;
}
