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

int x[7], y[7];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> x[i];
		sort(x, x + N);
		unordered_set<int> cases;
		for (int i = 0; i < N; i++) {
			cases.insert(x[i]);
			for (int j = 0; j < N; j++)
				if (x[i] > x[j])
					cases.insert(x[i] - x[j]);
		}

		int ans = 0;
		for (int A : cases) {
			for (int B : cases) {
				for (int C : cases) {
					if (A <= B && B <= C) {
						unordered_set<int> ss = {A, B, C, A + B, B + C, C + A, A + B + C};
						for (int i = 0; i < N; i++)
							if (!ss.count(x[i])) goto nxt;
						++ans; nxt:;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
