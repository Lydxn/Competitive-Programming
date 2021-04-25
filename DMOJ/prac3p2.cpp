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

bitset<10000000> yay;
int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	while (cin >> N) {
		if (N == 0) break;
		int ans = 1;
		for (yay.reset(); !yay[N]; ans++) {
			yay.set(N);
			int NN = 0;
			while (N) NN += f[N % 10], N /= 10;
			N = NN;
		}
		cout << ans << '\n';
	}
	return 0;
}
